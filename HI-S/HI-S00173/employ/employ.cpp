#include<bits/stdc++.h>
using namespace std;
const int N = 505;
char s[N];
int a[N];
int p[N];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,sum = 1;
    cin >> n >> m >> s+1;
    for(int i = 1;i<=n;++i)
    {
        cin >> a[i];
        p[i] = i;
        sum = sum*i;
    }
    int ans = 0;
    while(sum--)
    {
        /*for(int i = 1;i<=n;i++)
        {
            cout << p[i] << " ";
        }
        cout << "\n";*/
        int num = 0,cnt = 0;
        for(int i = 1;i<=n;++i)
        {
            if(s[i] == '1'&&num<a[p[i]])
            {
                //cout << p[i] << " ";
                ++cnt;
            }
            else
            {
                ++num;
            }
        }
        if(cnt>=m)
        {
            ++ans;
        }
        next_permutation(p+1,p+n+1);
    }
    cout << ans;
    return 0;
}