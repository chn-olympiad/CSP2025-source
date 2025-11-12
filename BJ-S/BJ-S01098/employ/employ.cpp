#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mod (998244353ll)
using namespace std;
int n,m,c[505];
ll dp[300005][21],ans;//来的人状压为i，至少录用j人的方案数
string s;
ll shu(int x){
    ll res=0;
    for(int i=1;i<=n;i++)if(c[i]<=x)res++;
    return res;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;s=" "+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    if(m==1){
        int used=0;
        ll all=1,ans=1,cnt0=0;
        for(int i=1;i<=n;i++){
            (all*=i)%=mod;
            if(s[i]=='0'){
                cnt0++;
                (ans*=cnt0)%=mod;
                continue;
            }
            (ans*=(shu(i-1)-used))%=mod;
            //cout<<i<<":"<<shu(i-1)-used<<"\n";
            used++;
        }
        cout<<(all-ans+mod)%mod<<"\n";
        return 0;
    }
    if(m==n){
        ll ans=1;
        for(int i=1;i<=n;i++){
            if(s[i]=='0')ans=0;
            else if(c[i]==0)ans=0;
            else (ans*=i)%=mod;
        }
        cout<<ans<<"\n";
        return 0;
    }
    dp[0][0]=1;
    for(int i=0;i<(1<<n);i++){
        int cnt=0;
        for(int j=1;j<=n;j++)
            if(i&(1<<(j-1)))cnt++;//已经来了cnt
        for(int j=0;j<=cnt;j++){
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
            for(int k=1;k<=n;k++){
                if(!(i&(1<<(k-1)))){
                    //cout<<"c:"<<c[k]<<" cnt="<<cnt<<" "<<s[cnt+1]<<"\n";
                    //cout<<"->"<<(i|(1<<(k-1)))<<",";
                    if(c[k]<=cnt-j||s[cnt+1]=='0')(dp[i|(1<<(k-1))][j]+=dp[i][j])%=mod;//,cout<<j<<"\n";
                    else (dp[i|(1<<(k-1))][j+1]+=dp[i][j])%=mod;//,cout<<j+1<<"\n";
                }
            }

        }
    }
    for(int i=m;i<=n;i++)(ans+=dp[(1<<n)-1][i])%=mod;
    cout<<ans;
    return 0;
}
