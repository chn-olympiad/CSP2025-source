#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
string a[500001];

string to_binary(int num)
{
    string tmp = "";
    while (num)
    {
        tmp = (char)(num % 2 + '0') + tmp;
        num /= 2;
    }
    while (tmp.length() < 32)
        tmp = '0' + tmp;
    return tmp;
}

int to_int(string bin)
{
    int tmp = 0;
    for (int i = 0; i <= 31; i++)
    {
        tmp += (bin[i] - '0') * pow(2, 31 - i);
    }
    return tmp;
}

string get_xor(string bin1, string bin2)
{
    string tmp = "";
    for (int i = 0; i <= 31; i++)
    {
        tmp += (char)((bool)(bin1[i] != bin2[i]) + '0');
    }
    return tmp;
}

int xor_plus(int l, int r)
{
    string tmp = a[l];
    for (int i = l + 1; i <= r; i++)
    {
        tmp = get_xor(tmp, a[i]);
    }
    return to_int(tmp);
}

int find(int l1)
{
    if (l1 >= n)
        return 0;
    for (int l = l1; l <= n; l++)
    {
        int r = l;
        while (r <= n)
        {
            if (xor_plus(l, r) == k)
            {
                return 1 + find(r + 1);
            }
            r++;
        }
    }
    return 0;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        a[i] = to_binary(tmp);
    }
    cout << find(1) << endl;
    return 0;
}