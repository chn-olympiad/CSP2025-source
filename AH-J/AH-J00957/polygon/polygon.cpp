#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[5005];
ll ans=0;
vector<ll> v;
void dfs(int p,int cnt){
	if(p==n+1){
		if(!v.empty()){
			ll mx=0;
			for(int i=0;i<v.size();i++) mx=max(mx,v[i]);
			if(cnt>mx*2) ans++;
		}
		return;
	}
	v.push_back(a[p]);
	dfs(p+1,cnt+a[p]);
	v.pop_back();
	
	dfs(p+1,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<ans%998244353<<endl;
	return 0;
}


