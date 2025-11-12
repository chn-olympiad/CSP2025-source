#include<bits/stdc++.h>
using namespace std;
int x[500005];
int t[2097158];
int dp[500005];
int n,k,maxn=0;

int find1(int x,int y){
    int ans=0,w=0;
    while(x>0||y>0){
        int yy=y&1,xx=x&1;
        if(yy==1)ans=ans+((1-xx)<<w);
        else ans=ans+(xx<<w);
        w++;
        x>>=1;y>>=1;
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        x[i]=x[i-1]^a;
    }
    for(int i=1;i<=n;i++){
        t[x[i]]=i;
        int ne=find1(x[i],k);
        dp[i]=dp[i-1];
        if(t[ne]>0||ne==0){
           dp[i]=max(dp[t[ne]]+1,dp[i-1]);
           //cout<<t[ne]+1<<" "<<i<<endl;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}


