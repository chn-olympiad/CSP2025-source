#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10,mod=998244353;
char s[N];
int a[N];
long long jc(long long n){
    long long ans=1;
    for(int i=2;i<=n;i++) ans*=i;
    return ans;
}
long long cj(long long n){
    long long ans=1;
    for(int i=2;i<=n;i++) ans=(ans*i)%mod;
    return ans;
}
long long ans;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,sum=0;
    scanf("%d%d",&n,&m);
    getchar();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n==m){
        for(int i=1;i<=n;i++) if(s[i]=='0'){
            printf("%d",0);
            return 0;
        }
        printf("%lld",cj(n));
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++) if(s[i]!='0'){
            printf("%lld",cj(n));
            return 0;
        }
        printf("0");
        return 0;
    }
    bool f=1;
    for(int i=1;i<=n;i++){
        if(s[i]=='1') sum++;
        if(s[i]!='1') f=0;
    }
    if(f){
        printf("%lld",cj(n));
        return 0;
    }
    if(sum<m){
        printf("0");
        return 0;
    }
    sort(a+1,a+n+1);
    long long nn=jc(n);
    for(long long i=1;i<=nn;i++){
        int t=0,p=0;
        for(int j=1;j<=n;j++){
            if(t>=a[j]) t++;
            else if(s[j]=='0') t++;
            else p++;
        }
        if(p>=m){
            ans=(ans+1)%mod;
            //for(int i=1;i<=n;i++) printf("%d ",a[i]);
            //printf("\n");
        }
        next_permutation(a+1,a+n+1);
    }
    printf("%lld",ans);
    return 0;
}
