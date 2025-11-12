#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int c[505],op[505];
int dp[1000005][21];
int dp2[505][505][505],jc[505],Jc[505];
int tong[505];;
int kuai_mi(int x,int y){
    int ans=1;
    while(y){
        if(y&1){
            ans*=x;
            ans%=mod;
        }
        x*=x;
        x%=mod;
    }
    return ans;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string ss;
    cin>>ss;
    ss=" "+ss;
    if(n<=18){
        for(int i=1;i<=n;i++){
            op[i]=(ss[i]=='1');
        }
        for(int i=1;i<=n;i++){
            cin>>c[i];
        }
        dp[0][0]=1;
        for(int i=0;i<(1<<n);i++){
            int N=0;
            for(int j=1;j<=n;j++){
                if((1<<j-1)&i){
                    N++;
                }
            }
            for(int k=0;k<=N;k++){
                for(int j=1;j<=n;j++){
                    if((1<<j-1)&i){
                        continue;
                    }
                    if(op[N+1]==0 || c[j]<=N-k){
                        dp[i+(1<<j-1)][k]+=dp[i][k];
                        dp[i+(1<<j-1)][k]%=mod;
                    }else{
                        dp[i+(1<<j-1)][k+1]+=dp[i][k];
                        dp[i+(1<<j-1)][k+1]%=mod;
                    }
                }
            }
        }
        int ans=0;
        for(int i=m;i<=n;i++){
            ans+=dp[(1<<n)-1][i];
            ans%=mod;
        }
        cout<<ans;
    }else if(m==1){
        int cnt=n;
        for(int i=1;i<=n;i++){
            op[i]=(ss[i]=='1');
            cnt-=op[i];
        }
        for(int i=1;i<=n;i++){
            cin>>c[i];
            tong[c[i]+1]++;
        }
        jc[0]=1;
        for(int i=1;i<=n;i++){
            jc[i]=jc[i-1]*i%mod;
            Jc[i]=Jc[i-1]*jc[i]%mod;
        }
        dp2[n+2][cnt][0]=1;
        for(int i=n+1;i>=1;i--){
            if(tong[i]==0){
                for(int j=0;j<=n;j++){
                    for(int k=0;k<=n;k++){
                        dp2[i][j][k]=dp2[i+1][j][k];
                    }
                }
            }else{
                for(int j=0;j<=tong[i];j++){
                    for(int k=j;k<=n;k++){
                        for(int K=max(0ll,tong[i]-j-op[i]);K<=n;K++){
                            dp2[i][k-j][K-tong[i]+j+op[i]]+=dp2[i+1][k][K]*Jc[k]%mod*kuai_mi(Jc[k-j],mod-2)%mod*Jc[K]%mod*kuai_mi(Jc[K-tong[i]+j],mod-2)%mod;
                            dp2[i][k-j][K-tong[i]+j+op[i]]%=mod;
                        }
                    }
                }
            }
        }
        int ans=Jc[n];
        ans-=dp2[1][0][0];
        cout<<(ans%mod+mod)%mod;
    }
    
    return 0;
}