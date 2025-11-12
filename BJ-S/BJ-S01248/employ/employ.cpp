#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int ksm(int a,int b)
{
    int base=1;
    while(b)
    {
        if(b%2==1)
        {
            base*=a;
            base%=mod;
        }
        a*=a;
        a%=mod;
        b/=2;
    }
    return base;
}
bool nd[505];
int c[505],jie[505];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;cin>>n>>m;
    string s;cin>>s;
    bool p=false,p1=false;
    for(int i=0;i<s.size();i++)
    {
        nd[i+1]=s[i]-'0';
        if(nd[i]==0) p=true;
        if(nd[i]==1) p1=true;
    }
    for(int i=0;i<=n;i++) cin>>c[i];
    jie[0]=1;
    for(int i=1;i<=n;i++) jie[i]=jie[i-1]*i%mod;
    if(p==false)
    {
        if(m==0) cout<<jie[n]%mod<<endl;
        if(m!=0) cout<<0<<endl;
    }
    else if(n==m&&p1==false) cout<<jie[n]<<endl;
    else if(n==m&&p1==true) cout<<0<<endl;
    return 0;
}
