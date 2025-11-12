#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int a[5010];
bool vis[5010];
vector<int> k;
int ans=0;
void dfs(int x,int n,int sum,int mmax){
    if(x>n+1){
        return ;
    }
    if(sum>2*mmax&&x>=3){
        for(int i=1;i<k.size();i++){
            if(k[i]<k[i-1]){
                return ;
            }
        }
        ans++;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            vis[i]=true;
            k.push_back(i);
            dfs(x+1,n,sum+a[i],max(mmax,a[i]));
            vis[i]=false;
            k.pop_back();
        }else{
            continue;
        }
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,n,0,0);
    cout<<ans%mod<<'\n';
    return 0;
}
