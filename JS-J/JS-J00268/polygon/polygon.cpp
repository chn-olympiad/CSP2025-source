#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,mod=998244353;
int n,a[N];
int ans,cnt,p[N];
int jie(int x){
    if(x==0||x==1) return 1;
    return (jie(x-1)*x)%mod;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n>=25){
        for(int i=2;i<=n-1;i++){
            ans=(jie(n-1)/((i*jie(n-1-i))%mod)+ans)%mod;
        }
        cout<<(ans*n)%mod;
        return 0;
    }
    for(int i=n;i>=1;i--){
        int w=a[i];
        int q;
        for(int j=i;j<=n;j++){
            if(a[j]!=a[j+1]&&a[j]==a[i]){
                q=j;
                break;
            }
        }
        while(p[0]==0){
            int k=q;
            p[i]=1;
            while(p[k]==1) k--;
            p[k]=1;
            for(int j=k+1;j<=q;j++){
                if(j==i) continue;
                p[j]=0;
            }
            for(int j=1;j<=q;j++){
                if(p[j]==1&&j!=i){
                    cnt+=a[j];
                }
            }
            if(cnt>w) ans=(ans+1)%mod;
            cnt=0;
        }
        memset(p,0,sizeof(p));
    }
    cout<<ans;
    return 0;
}
