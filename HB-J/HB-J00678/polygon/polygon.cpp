#include <bits/stdc++.h>
using namespace std;
const int N=10010,P=998244353;
int n,a[N],f[N],s[2][N],cnt[N];
int kpow(int a,int b){
    long long t=1;
    long long aa=a;
    while(b){
        if(b&1)t=t*aa%P;
        aa=aa*aa%P;
        b>>=1;
    }
    return (int)t;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int id=0;
    for(int i=1;i<=n;i++){
        f[0]=kpow(2,i-1);
        s[id][0]=(f[0]+s[id^1][0])%P;
        for(int j=1;j<=10000;j++){
            if(a[i]>j)f[j]=1;
            else f[j]=0;
            f[j]=(f[j]+s[id^1][max(j-a[i],0)])%P;
            s[id][j]=(s[id^1][j]+f[j])%P;
            //cout<<i<<' '<<j<<':'<<f[i][j]<<"\n";
        }
        cnt[i]=f[2*a[i]];
        id^=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+cnt[i])%P;
    }
    printf("%d",ans);
    return 0;
}