#include <iostream>
using namespace std;

int num[1000005], tmp[15], cur = 0, curr = 0;

bool cmp(int x, int y) {
    return x > y;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9')
            num[++cur] = s[i] - '0';
    for (int i = 1; i <= cur; i++) tmp[num[i]]++;
    for (int i = 9; i >= 0; i--)
        for (int j = 1; j <= tmp[i]; j++)
            num[++curr] = i;
    for (int i = 1; i <= curr; i++) cout << num[i];
    return 0;
}
