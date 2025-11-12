#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[505],n,m;
string s;
const int mod=998244353;
int vis[505],dis[505],tans;
void dfs(int x){
    if(x==n+1){
        int num=0,sus=0;
        for(int i=1;i<=n;i++){
            //c[vis]
            if(s[i-1]==49&&c[vis[i]]>num)sus++;
            else num++;
        }
        if(sus>=m)tans++;
    }
    for(int i=1;i<=n;i++){
        if(dis[i]==0){
            vis[x]=i;
            dis[i]=1;
            dfs(x+1);
            dis[i]=0;
            vis[x]=0;
        }
    }

}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    sort(c+1,c+n+1);
    if(m==1){
        int ans=1;
        for(int i=1;i<=n;i++)ans*=i,ans%=mod;
        int cnt=0,ans2=1;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1'){
                int sum=0;
                for(int j=1;j<=n;j++)if(c[j]<i)sum++;
                ans2*=(sum-cnt);ans2%=mod;
                cnt++;
            }
        }
        for(int i=1;i<=n-cnt;i++){
            ans2*=i;ans2%=mod;
        }
        cout<<(ans-ans2+mod)%mod;
    }else if(m==n){
        for(int i=0;i<s.size();i++){
            if(s[i]!=49){
                cout<<"0";
                return 0;
            }
        }
        for(int i=1;i<=n;i++){
            if(c[i]==0){
                cout<<"0";
                return 0;
            }
        }
        int ans=1;
        for(int i=1;i<=n;i++)ans*=i,ans%=mod;
        cout<<ans;
    }else if(n<=10){
        dfs(1);
        cout<<tans;
    }else{
        cout<<"0";
    }
    return 0;
}
