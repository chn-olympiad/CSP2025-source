#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>
void in(T &x){
    char c=getchar(); int f=1; x=0;
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    x*=f;
}
const int N=510,Mod=998244353;
int n,m,a[N];
char str[N];
ll f[1<<18][20];
void work1(){
    f[0][0]=1;
    for(int i=0;i<(1<<n);i++){
        int cnt=0;
        for(int j=0;j<n;j++) cnt+=(i>>j)&1;
        for(int j=0;j<=n;j++){
            f[i][j]%=Mod;
            for(int k=1;k<=n;k++){
                if((i&(1<<k-1))==0){
                    if(str[cnt+1]=='1'&&a[k]>cnt-j) f[i|(1<<k-1)][j+1]+=f[i][j];
                    else f[i|(1<<k-1)][j]+=f[i][j];
                }
            }
        }
    }
    ll ans=0;
    for(int i=m;i<=n;i++) ans+=f[(1<<n)-1][i];
    printf("%lld",ans%Mod);
}
void work2(){
    bool tag=1;
    if(a[1]==0){
        printf("0");
    }else{
        ll ans=1;
        for(int i=1;i<=n;i++) ans=ans*i%Mod;
        printf("%lld",ans);
    }
}
int cnt[N];
void work3(){
    for(int i=1;i<=n;i++)
        cnt[a[i]]++;
    for(int i=1;i<=n;i++)
        cnt[i]+=cnt[i-1];
    int tot=0; ll ans=1,ji=1;
    for(int i=1;i<=n;i++){
        if(str[i]=='0') tot++;
        else if(cnt[i-1]<i) ans=0;
        else ans=ans*(cnt[i-1]-i+1)%Mod;
    }
    for(int i=1;i<=tot;i++)
        ji=ji*i%Mod;
    ans=ans*ji%Mod;
    ji=0;
    for(int i=1;i<=tot;i++)
        ji=ji*i%Mod;
    printf("%lld\n",(ji-ans+Mod)%Mod);
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    in(n); in(m);
    scanf("%s",str+1);
    int cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=str[i]-'0';
    if(cnt<m){
        printf("0");
        return 0;
    }
    for(int i=1;i<=n;i++) in(a[i]);
    sort(a+1,a+n+1);
    if(n<=18){
        work1();
    }else if(n==m){
        work2();
    }else if(m==1){
        work3();
    }
    return 0;
}