#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5001],ans;
map<set<int>,int> vis;
void dfs(ll s,ll l,ll i,ll maxn){
	if(s>2*a[i]&&l>=3) ans++;
	if(i==n) return;
	set<int> v;
	for(int j=i;j<=n;j++){
		v.insert(a[j]);
		if(!vis[v]){
			vis[v]=1; 
			dfs(s+a[j],l+1,j+1,v.size()-1);
			vis[v]=0;
		}
	}
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(0,0,0,INT_MAX);
	cout<<ans;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
