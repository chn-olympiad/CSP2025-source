#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,x,ans=0;
vector<ll> s;

void dfs(ll p,ll a,ll qz,ll maxx,ll dx){
	for(int i=a;i<p;i++){
		ll o=maxx,flag=1;
		maxx=max(maxx,s[i]);
		qz+=s[i];
		if(dx<2){
			flag=0;
		}if(maxx*2<qz&&flag){
			ans++;
			ans%=998244353;
		}
		dfs(p,i+1,qz,maxx,dx+1);
		qz-=s[i];
		maxx=o;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		s.push_back(x);
	}ll p=s.size();
	dfs(p,0,0,INT_MIN,0);
	cout<<ans;
	return 0;
}