#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
const int mod=998244353;
int n;
ll a[N];
ll maxai;
ll ans;
bool vis[N];

void dfs(int k,ll sum,ll maxl,int u){
    if(k==n+1) return;
    if(k>=3){
        if(sum>2*maxl){
            ans++;
            if(ans==mod) ans=0;
        }

    }

    for(int i=u+1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=true;
        dfs(k+1,sum+a[i],max(maxl,a[i]),i);
        vis[i]=false;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxai=max(maxai,a[i]);
    }

    if(maxai==1){
        cout<<0;
        return 0;
    }

    dfs(0,0,0,0);
    cout<<ans;
	return 0;
}
