#include<iostream>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int n,a[5005],f[50050],maxn,after_maxn,tmp[50050];
const int mod=998244353;
int ans=0;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
    sort(a+1,a+n+1);
    //tmp[0]=1;
    f[0]=1;
    for(int i=1;i<=n;i++){
        //memset(f,0,sizeof(f));
        //f[0]=1;
        (ans+=after_maxn)%=mod;
        for(int j=2*a[i]+1;j<=3*maxn;j++) (ans+=f[j-a[i]])%=mod;
        (after_maxn*=2)%=mod;
        for(int j=2*maxn;j>=0;j--){
            if(j+a[i]>2*maxn) (after_maxn+=f[j])%=mod;
            else (f[j+a[i]]+=f[j])%=mod;
        }
        //for(int j=0;j<=2*maxn;j++) tmp[j]=f[j];
    }
    cout<<ans;
}