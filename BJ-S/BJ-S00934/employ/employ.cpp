#include <bits/stdc++.h>
#define rep(i,s,t) for(int i=s;i<=t;i++)
using namespace std;
const int N=1e5+11,mod=998244353;
int n,m,c[N];
long long ans=1;
char s[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    int flag=1,sum=0;
    rep(i,1,n){
        if(s[i]=='0'){
            flag=0;
            break;
        }
    }
    rep(i,1,n){
        scanf("%d",c+i);
        if(c[i]>0)sum++;
    }
    if(flag==1)
        rep(i,1,sum)ans=ans*i%mod;
    printf("%lld\n",ans%mod);
    return 0;
}
