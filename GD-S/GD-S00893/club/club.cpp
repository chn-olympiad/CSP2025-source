#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+5;
int T,n,a[N][5],q[N],num[4];
ll ans;

void check(){
	ll res=0;
	for(int i=1;i<=n;i++) res+=a[i][q[i]];
	ans=max(ans,res);
	//for(int i=1;i<=n;i++) cout<<q[i]<<" ";
	//cout<<"\n";
}

void dfs(int dep){
	if(dep>n){
		check();
		return;
	}
	for(int i=1;i<=3;i++){
		if(num[i]+1>n/2) continue;
		q[dep]=i;
		num[i]++;
		dfs(dep+1);
		num[i]--;
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=3;++j)
				cin>>a[i][j];
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
