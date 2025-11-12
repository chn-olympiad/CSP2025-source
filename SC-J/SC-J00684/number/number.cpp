# include <iostream>
# include <algorithm>
# include <vector>
# include <cstdio>
using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;
    vector<int> numbers;
    for (int i = 0; i < s.size(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            numbers.push_back(s[i] - '0');
        }
    }
    sort(numbers.begin(), numbers.end(), comp);
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
