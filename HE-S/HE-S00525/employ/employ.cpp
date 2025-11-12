#include <cstdio>
int mod=998224353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    char a[1000];
    scanf("%s",a);
    int c;
    for(int i=0; i<n; ++i)
        scanf("%d",&c);


    long long int ans=1;
    for(int i=1; i<=n; ++i){
        ans*=n;
        ans%=mod;
    }
    if(m==1){
        ans*=n;
        ans%=mod;
    }
    printf("%d",ans);
    return 0;
}
