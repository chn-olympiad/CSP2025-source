#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int c[505],pe[505],w[505],b[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,ans;
    string s;
    cin >> n >> m >> s;
    memset(pe,0,sizeof(pe));
    memset(w,0,sizeof(w));
    memset(b,0,sizeof(w));
    for(int i = 1;i <= n;i++)
    {
        cin >> c[i];
    }
    for(int i = 0;i <= n - 1;i++)
    {
        pe[i] = (int)s[i] + pe[i -1];
        for(int j = 1;j <= n;j++)
        {
            if(pe[i] == c[j]) w[j] = i;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        b[w[i]]++;
    }
    for(int i = 1;i <= n;i++)
    {
        if(b[i] <= 0)
        {
            b[i + 1] --;
        }
        else
        {
            ans *= b[i];
        }
    }
    cout << ans %998 % 244 % 353 << endl;
    return 0;
}
