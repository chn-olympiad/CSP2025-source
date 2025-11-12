#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,mod=998244353;
int a[N],c[N];
string s;


signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    cin>>s,s=' '+s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    if(n<=10)
    {
        for(int i=1;i<=n;i++)
            a[i]=i;
        do
        {
            int num=0;
            for(int i=1;i<=n;i++)
                if(num>=c[a[i]]||s[i]=='0') num++;
            if(n-num>=m) ans++;
        }
        while(next_permutation(a+1,a+1+n));
    }
    else if(m==n)
    {
        ans=1;
        for(int i=1;i<=n;i++)
            ans=ans*i%mod;
        for(int i=1;i<=n;i++)
            if(s[i]=='0'||c[i]==0) ans=0;
    }
    cout<<ans<<endl;
    return 0;
}//Ren5Jie4Di4Ling5%
