#include<bits/stdc++.h>
using namespace std;
#define ll long long;
#define pii pair<int,int>
#define st(s) sort(s.begin(),s.end())
#define pb(n) push_back(n)
#define rv(s) reverse(s.begin(),s.end())
#define ins(n) insert(n)
#define vt vector
#define endl "\n"
int dp[500010];//if last with a[i],there are dp[i]
int qzh[500010];
int zdq[500010];
int biggest(int n){
    if(zdq[n]==-1){
        if(n==0){
            zdq[0]=dp[0];
            return dp[0];
        }
        int res=max(dp[n],biggest(n-1));
        zdq[n]=res;
        return res;
    }else{
        return zdq[n];
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,maxn,flag;
    cin>>n>>k;
    fill(zdq,zdq+n+2,-1);
    for(int i=1;i<=n;i++){
        cin>>qzh[i];
        qzh[i]^=qzh[i-1];
    }
    for(int i=1;i<=n;i++){
        maxn=0;
        for(int j=i-1;j>=0;j--){
            if((qzh[i]^qzh[j])==k){
                maxn=biggest(j)+1;
                break;
            }
        }
        dp[i]=maxn;
    }
    maxn=0;
    for(int i=0;i<=n;i++){
        maxn=max(maxn,dp[i]);
        //cout<<dp[i]<<endl;
    }
    cout<<maxn;
    return 0;
}
//100 points
