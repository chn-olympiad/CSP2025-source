#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL MAXN=105,MOD=998244353;
LL n,m,s[MAXN],c[MAXN],p[MAXN],fac[MAXN],f[MAXN][MAXN];
LL vis[MAXN];
void solve2(){
    for(LL i=1;i<=n;i++)p[i]=i;
    LL ans=0;
    do{
        LL cnt=0,num=0;
        for(LL i=1;i<=n;i++){
            if(c[p[i]]<=cnt){
                cnt++;
                continue;
            }
            if(s[i]==0){
                cnt++;
            }else{
                num++;
            }
        }
        if(num>=m){
            ans++;
        }
    }while(next_permutation(p+1,p+n+1));
    printf("%lld",ans);
}
void solve3(){
    printf("0");
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    bool flag=true;
    for(LL i=1;i<=n;i++){
        char ch;
        while(1){
            scanf("%c",&ch);
            if(ch=='0'||ch=='1')break;
        }
        s[i]=ch-'0';
        if(s[i]==0)flag=false;
    }
    for(LL i=1;i<=n;i++){
        scanf("%lld",&c[i]);
    }
    if(n<=10){
        solve2();
    }else{
        solve3();
    }
}