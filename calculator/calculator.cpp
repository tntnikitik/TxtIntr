#include <iostream>
#include <cmath>
#include <string>

double calculateAtanDegrees(double operand) {
    return std::atan(operand) * (180.0 / M_PI);
}

double calculateAtanRadians(double operand) {
    return std::atan(operand);
}

double calculateAcotDegrees(double operand) {
    return (M_PI / 2) - std::atan(1 / operand) * (180.0 / M_PI);
}

double calculateAcotRadians(double operand) {
    return (M_PI / 2) - std::atan(1 / operand);
}

void printUsage() {
    std::cout << "Usage: calculator -o <operation> <operand>" << std::endl;
    std::cout << "Operations:" << std::endl;
    std::cout << "  -o atan_deg <operand> : Compute arctangent in degrees" << std::endl;
    std::cout << "  -o atan_rad <operand> : Compute arctangent in radians" << std::endl;
    std::cout << "  -o acot_deg <operand> : Compute arccotangent in degrees" << std::endl;
    std::cout << "  -o acot_rad <operand> : Compute arccotangent in radians" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printUsage();
        return 1;
    }

    std::string operation = argv[2];
    double operand = std::stod(argv[3]);

    if (operation == "atan_deg")
        std::cout << "Result: " << calculateAtanDegrees(operand) << " degrees" << std::endl;
    else if (operation == "atan_rad")
        std::cout << "Result: " << calculateAtanRadians(operand) << " radians" << std::endl;
    else if (operation == "acot_deg")
        std::cout << "Result: " << calculateAcotDegrees(operand) << " degrees" << std::endl;
    else if (operation == "acot_rad")
        std::cout << "Result: " << calculateAcotRadians(operand) << " radians" << std::endl;
    else {
        std::cout << "Invalid operation: " << operation << std::endl;
        printUsage();
        return 1;
    }

    return 0;
}
