#include <iostream>

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    std::string s; //The input
    std::cin >> s;
    int res[s.length()]; //The Data of only number in "s"
    unsigned long long int
        one=0,
        two=0,
        three=0,
        four=0,
        five=0,
        six=0,
        seven=0,
        eight=0,
        nine=0,
        zero=0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '9' && s[i] <= '0')
            continue;
        switch (s[i] - '0')
        {
        case 1:
            one++;
            break;
        case 2:
            two++;
            break;
        case 3:
            three++;
            break;
        case 4:
            four++;
            break;
        case 5:
            five++;
            break;
        case 6:
            six++;
            break;
        case 7:
            seven++;
            break;
        case 8:
            eight++;
            break;
        case 9:
            nine++;
            break;
        case 0:
            zero++;
            break;
        }
    }
    for (int i = 0; i < nine; i++)
    {
        std::cout << "9";
    }
    for (int i = 0; i < eight; i++)
    {
        std::cout << "8";
    }
    for (int i = 0; i < seven; i++)
    {
        std::cout << "7";
    }
    for (int i = 0; i < six; i++)
    {
        std::cout << "6";
    }
    for (int i = 0; i < five; i++)
    {
        std::cout << "5";
    }
    for (int i = 0; i < four; i++)
    {
        std::cout << "4";
    }
    for (int i = 0; i < three; i++)
    {
        std::cout << "3";
    }
    for (int i = 0; i < two; i++)
    {
        std::cout << "2";
    }
    for (int i = 0; i < one; i++)
    {
        std::cout << "1";
    }
    for (int i = 0; i < zero; i++)
    {
        std::cout << "0";
    }
    fclose(stdin);
	fclose(stdout); 
    return 0;
}
