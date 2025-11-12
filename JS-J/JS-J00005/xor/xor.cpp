#include<bits/stdc++.h>
#define fi first
#define se second 
#define pii pair<int,int>
using namespace std;

const int N=5e5+10,maxn=4e6+10;

int n,k,ans=0;
int a[N];
bool vis[maxn];
queue<int> q;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=0;
    for(int i=1;i<=n;i++){
        bool flag=false;
        int tot=q.size();
        vector<int> vec;
        for(int j=1;j<=tot;j++){
            int cur=q.front(); q.pop();
            vis[cur]=false; vec.push_back(cur);
        }
        for(auto cur:vec){
            cur^=a[i];
            if(cur==k){
                ans++; flag=true;
                break;
            }
            if(!vis[cur]){
                vis[cur]=true;
                q.push(cur);
            }
        }
        if(i<=n && !vis[a[i]]) q.push(a[i]),vis[a[i]]=true;
        // /**/ if(i<=n) q.push(a[i]);
        if(!flag && i<=n && a[i]==k) ans++,flag=true;
        if(flag){
            while(!q.empty()){
                vis[q.front()]=false; q.pop();
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}