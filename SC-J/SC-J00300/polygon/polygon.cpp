#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5100];
int n=0,ans=0;
bool vis[5100];
vector<int>v;
void dfs(int d,int id){
	if(d>=3){
		int sum=0,maxx=0;
		for(int i=0;i<v.size();i++){
			sum+=v[i];
			maxx=max(maxx,v[i]);
//			cout<<v[i]<<" ";
		}
		if(sum>maxx*2){
//			cout<<"YES";
			ans++;
			ans%=998244353;
		}
//		cout<<"\n";
	}
	if(d==n){
		return ;
	}
	for(int i=id;i<=n;i++){
		if(vis[i]==0){
			v.push_back(a[i]);
			vis[i]=1;
			dfs(d+1,i);
			v.pop_back();
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1);
	cout<<ans;
	return 0;
} 