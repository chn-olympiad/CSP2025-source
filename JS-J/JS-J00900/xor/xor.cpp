#include <bits/stdc++.h>
using namespace std;

int fread()
{
    int r = 0;
    char ch;
    ch = getchar();
    while ('0' <= ch && ch <= '9')
    {
        r = r*10 + (ch - '0');
        ch = getchar();
    }
    return r;
}

const int SIZE = 500005;
int a[SIZE];
string sra[SIZE] = {"0"};
int dp[SIZE];

string stor(int n) {
    string str = "";
    while(n != 0)
    {
        if (n % 2 == 1)
            str = str + "1";
        else
            str = str + "0";
        n /= 2;
    }
    return str;
}

string Xor(string a, string b) {
    if (b.size() > a.size())
    {
        string x = a;
        a = b;
        b = x;
    }
    string c = "";
    for (int i = 0; i < b.size(); i++)
    {
        if (a[i] != b[i])
            c = c + "1";
        else
            c = c + "0";
    }
    c = c + a.substr(b.size());
    return c;
}

int rtos(string str) {
    int n = 0;
    for (int i = str.size()-1; i >= 0; i--)
    {
        n *= 2;
        n += str[i] - '0';
    }
    return n;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    n = fread();
    k = fread();
    for (int i = 1; i <= n; i++)
    {
        a[i] = fread();
        sra[i] = Xor( sra[i-1], stor(a[i]) );
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (rtos(Xor(sra[i], sra[j])) == k)
                dp[i] = max(dp[j] + 1, dp[i]);
            else dp[i] = max(dp[j], dp[i]);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
