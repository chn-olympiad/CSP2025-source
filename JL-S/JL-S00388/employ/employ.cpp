#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,tj=0;
    string s;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        int xy;
        cin>>xy;
        if(xy!=0)
        {
            tj++;
            a[tj]=xy;
        }
    }
    sort(a+1,a+tj+1);
    if(tj<m)
    {
        cout<<0;
        return 0;
    }
    if(m==n)
    {
        int ans=1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                ans=0;
            }
        }
        if(ans==1)
        {
            for(int i=1;i<=n;i++)
            {
                ans*=i;
                ans%=998244353;
            }
        }
        cout<<ans;
        return 0;
    }

    return 0;
}
