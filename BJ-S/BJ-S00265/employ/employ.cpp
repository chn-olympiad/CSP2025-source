#include <bits/stdc++.h>
using namespace std;
const int p=998244353;
long long n,m,ans,c[600],dp[1<<20][20];
string ss;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>ss;
    ss=" "+ss;
    for(int i=0;i<n;i++) cin>>c[i];
    dp[0][0]=1;
    for(int s=0;s<(1<<n);s++){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s&(1<<i)) cnt++;
        }
        // cout<<s<<":"<<cnt<<endl;
        for(int j=0;j<=cnt;j++){
            for(int i=0;i<n;i++){
                if(!(s&(1<<i))){
                    if(cnt-j<c[i] && ss[cnt+1]=='1'){
                        // cout<<"dp["<<s<<"]["<<j<<"]->dp["<<(s|(1<<i))<<"]["<<j+1<<"]\n";
                        dp[s+(1<<i)][j+1]+=dp[s][j];
                        dp[s+(1<<i)][j+1]%=p;
                    }else{
                        // cout<<"dp["<<s<<"]["<<j<<"]->dp["<<(s|(1<<i))<<"]["<<j<<"]\n";
                        dp[s+(1<<i)][j]+=dp[s][j];
                        dp[s+(1<<i)][j]%=p;
                    }
                }
            }
            // cout<<"dp["<<s<<"]["<<j<<"]="<<dp[s][j]<<endl;
            if(j>=m) ans=(ans+dp[s][j])%p;
        }
    }
    cout<<ans;

    return 0;
}

