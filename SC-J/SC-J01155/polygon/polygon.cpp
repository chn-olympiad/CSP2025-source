#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int N=5e5+5,M=1e6+5e4,mod=1e9+7;
int n,a[N],vis[5005],ans;
void dfs(int id,int sum,int maxx,int x){
	if(id>3&&sum>maxx*2){
		ans++;
	}
	if(id>n) return ;
	for(int i=x+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(id+1,sum+a[i],max(maxx,a[i]),i);
			vis[i]=0;
		}
	}
	
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
} 