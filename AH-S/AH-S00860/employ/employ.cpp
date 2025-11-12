#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
long long n,m,f[505],a[505],fl,ans,p[15];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=i;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')fl=1;
    }
    if(!fl||m==0)
    {
        cout<<n*(n+1)/2;
    }
    else
    {
        p[1]=1;
        for(int i=2;i<=n;i++)
        {
            p[i]=p[i-1]*i;
        }
        for(int j=1;j<=p[n];j++)
        {
            fl=0;
            long long no=0;
            for(int i=1;i<=n;i++)
            {
                if(no>=a[f[i]])no++;
                else
                {
                    if(s[i-1]=='0')no++;
                }
            }
            if(n-no>=m)ans++;
            next_permutation(f+1,f+n+1);
        }
        cout<<ans;
    }
    return 0;
}
