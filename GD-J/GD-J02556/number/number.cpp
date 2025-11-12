#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    unordered_map<int, int> nums;
    char a;
    while (cin >> a)
    {
        if ('0' <= a && a <= '9')
        {
            nums[a - '0']++;
        }
    }
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < nums[i]; j++)
        {
            cout << i;
        }
    }
    return 0;
}