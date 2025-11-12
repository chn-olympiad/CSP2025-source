#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const int N=505;
char cd[N];
ll n,ans,m;
ll c[N],v[N],d[N];

ll Make(){
	ll outt=0,is_ok=0;
	
	for(int i=1;i<=n;i++){
		if(cd[i]=='0'&&outt<v[i]){
			outt++;
		}else if(cd[i]=='1'&&outt<v[i]){
			is_ok++;
		}
	}
	return is_ok>=m;
}

void dfs(ll l){
	if(l==n){
		ans+=Make();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!d[i]){
			d[i]=1;
			v[l+1]=c[i];
			dfs(l+1);
			v[l+1]=d[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>cd[i];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}


