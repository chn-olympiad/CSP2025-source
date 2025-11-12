#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int ss = 0;
    int c[500];
    for (int i = 0;i < n;i++)
    {
        cin >> c[i];
        if (c[i] == 0) ss++;
    }
    n -= ss;
    int tt = 0;
    int q = 1;
    for (long long i = 0;i < n-m+1;i++)
    {
        int (int j = q;j <= n;j++)
        {
            type *= j;
        }
        tt += type;
        q++;
    }
    cout << tt % 998244353;
    fclose(stdin);
    fclose(stdout);

}
