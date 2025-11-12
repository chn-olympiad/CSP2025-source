#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int kmaxn=505,mod=998244353;
int n,m,s[kmaxn],c[kmaxn];
int dp[2][kmaxn][kmaxn];//前缀-1个数，还剩多少个
int qr[kmaxn],cnt[kmaxn];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    qr[0]=1;
    for(int i=1;i<=n;i++){
        qr[i]=qr[i-1]*i%mod;
        char x;cin>>x;
        s[i]=x-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];cnt[c[i]]++;
    }
    for(int i=n;i>=0;i--)cnt[i]+=cnt[i+1];
    for(int i=0;i<=n;i++){
        dp[0][0][i]=qr[n-i];
    }
    for(int i=1;i<=n;i++){
        int v=i%2,u=(v^1);
//        cout<<v<<"!!"<<endl;
        for(int j=0;j<kmaxn;j++){
            for(int k=0;k<kmaxn;k++){
//                cout<<v<<" "<<j<<" "<<k<<endl;
                dp[v][j][k]=0;
            }
        }
//        cout<<"!!"<<endl;
        if(s[i]==0){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    (dp[v][j+1][k]+=dp[u][j][k])%=mod;
                }
            }
        }else{
//        cout<<"!!"<<endl;
            //不放弃
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    if(cnt[j+1]>=k){
                        (dp[v][j][k]+=dp[u][j][k+1]*(cnt[j+1]-k))%=mod;
                    }
                }
            }
//        cout<<"!!"<<endl;
            //放弃了
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    if(cnt[j+1]>=k){
                        (dp[v][j+1][k]+=dp[u][j][k+1]*(cnt[j+1]-k)%mod*(mod-1))%=mod;
                    }
                }
            }
//        cout<<"!!"<<endl;
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    (dp[v][j+1][k]+=dp[u][j][k])%=mod;
                }
            }
        }
    }
    int v=n%2;
    int ans=0;
    for(int i=0;i<=n-m;i++){
        ans=(ans+dp[v][i][0])%mod;
    }
    cout<<ans<<"\n";
    return 0;
}