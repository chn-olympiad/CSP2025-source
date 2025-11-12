#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7;
int n,k,ans,cnt;
int num[MAXN];
bool vis[MAXN];
int res[MAXN];
int dfs(int now){
    if(now==n+1) return 0;
    if(vis[now]){
        return res[now];
    }else{
        vis[now]=1;
        int sum=num[now];
        int o=now;
        while(sum!=k && o<n){
            o++;
            sum^=num[o];
        }
        return res[now]=max(dfs(now+1),dfs(o+1)+(sum == k));
    }

}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    cout<<dfs(1);
    return 0;
}
