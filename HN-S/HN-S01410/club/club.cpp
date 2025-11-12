#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const int N=1e5+5;
map<int,int>v;
ll t,ans,n;
ll a[N][5],s[15];

void dfs(ll x,ll sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(s[i]<n/2){
			s[i]++;
			dfs(x+1,sum+a[x][i]);
			s[i]--;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		v.clear();
		s[1]=s[2]=s[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}


