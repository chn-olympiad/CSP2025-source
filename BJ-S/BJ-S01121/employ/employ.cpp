#include <bits/stdc++.h>

using namespace std;
const long long mod=998244353;
int n,m;
bool b[510];
int c[510];
int a[10]={1,2,3,4,5,6,7,8,9,10};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    bool fl=1;
    char cc;
    for(int i=1;i<=n;i++)
    {
        cin>>cc;
        b[i]=cc-'0';
        if(b[i]==0) fl=0;
    }

    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(m==n)
    {
        if(fl==0)
        {
            cout<<0;
            return 0;
        }
        else
        {
            long long ans=1;
            for(int i=1;i<=n;i++)
            {
                ans*=n;
                ans%=mod;
            }
            cout<<ans;
            return 0;
        }
    }
    else if(n<=10)
    {
        int ans=0;
        int kkk=1;
        for(int i=1;i<=n;i++) kkk*=i;
        for(int i=1;i<=kkk;i++)
        {
            int fail=0;
            for(int j=0;j<n;j++)
            {
                if(b[j]==0) fail++;
                else
                {
                    if(fail>=c[a[j]]) fail++;
                }
            }
            if(fail+m<=n) ans++;
            next_permutation(a,a+n);
        }

        cout<<ans;
    }
    return 0;
}
//炸了，退竞了  = |
