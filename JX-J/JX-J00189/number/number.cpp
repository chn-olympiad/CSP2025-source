#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("number.in");
    ofstream fout("number.out");
    string str;
    vector <int> numbers;
    fin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            numbers.push_back(str[i]-'0');
        }
    }

    sort(numbers.begin(), numbers.end());

    for (int j = numbers.size()-1; j >= 0; j--) {
        fout << numbers[j];
    }

    fout << '\n';

    return 0;
}
