#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int n,k,s,cnt,a[maxn][21];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    bool fa = 1,fb = 1;
    for(int i = 1;i <= n;i++)
    {
        cnt = 0;
        cin >> s;
        if(s != 1) fa = 0;
        if(s != 1 && s != 0) fb = 0;
        while(s)
        {
            a[i][cnt++] = s&1;
            s >>= 1;
        }
    }
    if(fa)
    {
        if(k == 1) cout << n;
        else if(k == 0)cout << n/2;
        else cout << 0;
        return 0;
    }
    else if(fb)
    {
        if(k == 1)
        {
            int sum = 0;
            for(int i = 1;i <= n;i++)
            {
                if(a[i][0] == 1) sum++;
            }
            cout << sum;
        }
        else if(k == 0)
        {
            int sum = 0;
            for(int i = 1;i <= n;i++)
            {
                if(a[i][0] == 0) sum++;
                else if(a[i][0] == 1)
                {
                    if(i > 1 && a[i-1][0] == 1)
                    {
                        sum++;
                        a[i][0] = 0;
                    }
                }
            }
            cout << sum;
        }
        return 0;
    }
    return 0;
}
