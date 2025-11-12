#include<bits/stdc++.h>
using namespace std;
int a[5010],f[5010],ans,prime[5010];
inline void solve(int n,int tar,int prev){
    if(tar>0)ans++;
    for(int i=prev+1;i<=n;i++){
        if(tar-a[i]<=0)break;
        solve(n,tar-a[i],i);
    }
    return;
}
void f2(int n){
    int cnt=2;
    while(n<=cnt){while(n%cnt==0){n/=cnt;prime[cnt]++;}cnt++;}
}
void f1(int n){
    int cnt=2;
    while(n<=cnt){while(n%cnt==0){n/=cnt;prime[cnt]--;}cnt++;}
}
int c(int n,int m){
    long long s=1;
    f1(m);
    f2(n-m+1);
    for(int i=n;i>=2;i--){
        for(int j=1;j<=prime[i];j++)s=(1ll*s*i)%988244353;
    }
    return (int)s;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,flag=1;
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a[i];if(a[i]>1)flag=0;}
    if(flag==1){
        for(int i=3;i<=n;i++){
            ans+=c(n,i);
            ans%=988244353;
        }
        cout<<ans;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
    for(int i=3;i<=n;i++){
        if(f[i-1]>a[i])solve(i-1,f[i-1]-a[i],0);
    }
    cout<<ans;
    return 0;
}
/*10:36 80pts?
cha le ban ge xiao shi fa xian
/bangbangt
*/
