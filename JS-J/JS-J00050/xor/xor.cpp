#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll qzh[N],a[N];
ll dp[N][2];
ll maxn=0;
int f[505];
int l[N];
map<ll,int> mp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i],maxn=max(maxn,a[i]);
    qzh[1]=a[1];
    for(int i=2; i<=n; i++){
        qzh[i]=qzh[i-1]^a[i];
    }
    if(n<=1000){
        for(int i=1; i<=n; i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            for(int j=i; j>=1; j--){
                if((qzh[i]^qzh[j-1])==k){
                    dp[i][1]=max(dp[i][1],max(dp[j-1][0],dp[j-1][1])+1);
                    break;
                }
            }
        }
        cout<<max(dp[n][0],dp[n][1]);
    }else if(maxn<=255){
        memset(f,-1,sizeof(f));
        f[0]=0;
        for(int i=1; i<=n; i++){
            int p=(qzh[i]^k);
            if(k==0&&a[i]!=0) l[i]=f[p]+1;
            else{
                f[qzh[i]]=i;
                l[i]=f[p]+1;
            }
        }
        for(int i=1; i<=n; i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            if(l[i]==0) continue;
            ll t=max(dp[l[i]-1][0],dp[l[i]-1][1])+1;
            dp[i][1]=max(dp[i][1],t);
        }
        cout<<max(dp[n][0],dp[n][1]);
    }else{
        mp[0]=0;
        for(int i=1; i<=n; i++){
            int p=(qzh[i]^k);
            if(k==0&&a[i]!=0){
                if(mp.count(p)) l[i]=mp[p]+1;
            }
            else{
                mp[qzh[i]]=i;
                if(mp.count(p)) l[i]=mp[p]+1;
            }
        }
        for(int i=1; i<=n; i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            if(l[i]==0) continue;
            ll t=max(dp[l[i]-1][0],dp[l[i]-1][1])+1;
            dp[i][1]=max(dp[i][1],t);
        }
        cout<<max(dp[n][0],dp[n][1]);
    }
    return 0;
}
