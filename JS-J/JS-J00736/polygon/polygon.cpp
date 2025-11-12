#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10,mod=998244353;
int a[maxn];
int f[maxn][maxn];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    bool ok=true;
    f[1][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            f[i][j]=(f[i-1][j]%mod+f[i-1][j-1]%mod)%mod;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            ok=false;
        }
    }
    if(ok){
        int ans=0;
        for(int i=3;i<=n;i++){
            ans=(ans%mod+f[n][i]%mod)%mod;
        }
        cout<<ans;
        return 0;
    }
    int ans=0;
    for(int i=3;i<=n;i++){
        int s=0;
        int t[maxn],cnt[maxn];
        memset(t,0,sizeof(t));
        bool p=true;
        for(int j=1;j<=i;j++){
            t[a[j]]++;
        }
        do{
            int mx=-1,sum=0;
            for(int j=1;j<=i;j++){
                sum+=a[j];
                mx=max(mx,a[j]);
            }
            for(int j=1;j<=i;j++){
                cnt[a[j]]++;
            }
            for(int j=1;j<=mx;j++){
                if(t[j]!=cnt[j]){
                    if(sum>mx*2){
                        s=(s%mod+1)%mod;
                    }
                    break;
                }
            }
            for(int j=1;j<=mx;j++){
                t[j]=cnt[j];
                cnt[j]=0;
            }
        }while(next_permutation(a+1,a+n+1));
        int c=1;
        for(int j=1;j<=i;j++){
            c*=j;
        }
        s/=c;
        ans=(ans%mod+s%mod)%mod;
    }
    cout<<ans;
    return 0;
}
