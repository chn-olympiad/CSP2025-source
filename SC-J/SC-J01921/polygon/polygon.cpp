#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=998244353;
vector<int>v;
int a[1000001],vis[1000001],ans;
void dfs(int l,int r,int id){
	if(id>=3){
		int sum=0,maxn=0;
		for(int i = 0;i<v.size();i++){
			sum+=v[i];
			maxn = max(maxn,v[i]);
//			cout<<v[i]<<' ';
		}
//		cout<<endl;
		if(sum>2*maxn){
			ans = (ans+1)%M;
		} 
	}
	for(int i = l;i<=r;i++){
		if(vis[i]==0){
			vis[i] = 1;
			v.push_back(a[i]);
			dfs(i+1,r,id+1);
			v.pop_back();
			vis[i] = 0;
		}
		
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	} 
	dfs(1,n,0);
	cout<<ans;
	return 0;
}
