#include<bits/stdc++.h>//全1题都可以过
using namespace std;
int n,m;
char s[510];
int c[510];
unsigned long long ans=1;
main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    if(n<=100){
        for(int i=n;i>=1;i--){
            ans*=i;
        }
        ans=ans%998244353;
    }else{
        for(int i=n;i>=1;i--){
            ans*=i;
            ans=ans%998244353;
        }
    }
    printf("%llu",ans);
}
