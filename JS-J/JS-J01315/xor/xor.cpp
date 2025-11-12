#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int a[N]={0},dp[N]={0},vis[N],l,ans;
int n,k;
vector<pair<int,int> >sz;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)dp[i]=a[i];
        else dp[i]=dp[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int qjv;
            if(i==1)qjv=dp[j];
            else qjv=dp[j]^dp[i-1];
            if(qjv==k){
                sz.push_back(make_pair(i,j));
            }
        }
    }
    l=sz.size(),ans=0;
    for(int i=0;i<l;i++){
        int st=sz[i].first,ed=sz[i].second;
        memset(vis,0,sizeof(vis));
        for(int j=st;j<=ed;j++)vis[j]=1;
        int cnt=1;
        for(int j=i+1;j<l;j++){
            int tp=sz[j].first,tl=sz[j].second;
            int pass=1;
            for(int k=tp;k<=tl;k++){
                if(vis[k]){
                    pass=0;
                    break;
                }
            }
            if(pass){
                cnt++;
                for(int k=tp;k<=tl;k++){
                    vis[k]=1;
                }
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}

