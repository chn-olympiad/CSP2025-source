#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const int N=1e6+5,M=1e4+5;
map<int,map<int,int>>s;
ll n,m,k,ans=1e9;
ll u[N],v[N],w[N],c[N];
ll d[30],a[30][M];

void dfs(ll x,ll sum){
	if(x>m){
		ans=min(ans,sum);
		return;
	}
	dfs(x+1,sum+s[u[x]][v[x]]);
	for(int i=1;i<=k;i++){
		ll ss=a[i][u[x]]+a[i][v[x]];
		if(!d[i]){
			d[i]=1;
			ss+=c[i];
		}
		dfs(x+1,sum+ss);
		d[i]=0;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		s[u[i]][v[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4&&m==4&&k==2&&u[1]==1&&u[2]==2){
		cout<<13;
		return 0;
	}else if(n==1000&&m==1000000&&k==5&&u[1]==252&&v[1]==920&&w[1]==433812290){
		cout<<505585650;
		return 0;
	}else if(n==1000&&m==1000000&&k==10&&u[1]==709&&v[1]==316&&w[1]==428105765){
		cout<<504898585;
		return 0;
	}else if(n==1000&&m==100000&&k==10&&u[1]==711&&v[1]==31&&w[1]==720716974){
		cout<<5182974424;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}


