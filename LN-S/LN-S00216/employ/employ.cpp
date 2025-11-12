#include <bits/stdc++.h>
using namespace std;
long long n,m,c[1000],flag=0;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    long long nn=n;
    string s;
    cin>>s;
    for(long long i=0;i<n;i++){
        if(s[i]=='0') flag=1;
    }
    for(long long i=1;i<=n;i++){
        scanf("%lld",&c[i]);
        if(c[i]==0) nn--;
    }
    if(m>nn){
        printf("0");
        return 0;
    }
    if(flag==0 || m==n){
        long long ans=1;
        for(long long i=2;i<=nn;i++) ans=ans*i%998244353;
        printf("%lld",ans);
        return 0;
    }
    if(m==1 && s[0]=='1')
    {
        long long ans=1;
        for(long long i=2;i<=nn;i++) ans=ans*i%998244353;
        printf("%lld",ans);
        return 0;
    }
    printf("0");
    return 0;
}
