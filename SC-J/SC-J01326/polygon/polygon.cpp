#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5002],ans,vis[5002],tot3;
void dfs(int x,int p,int val,int mx){
    if(x>=3&&val>mx*2){
       // cout<<x<<" "<<val<<" "<<mx<<"\n";
        ans++;
    }
    for(int i=p+1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(x+1,i,val+a[i],max(mx,a[i]));
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,0,0);
	cout<<ans%998244353;
}