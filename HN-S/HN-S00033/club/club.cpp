#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[3][100005],maxn;
void dfs(int x,int sum,int suma,int sumb,int sumc){
	if(suma>n||sumb>n||sumc>n)return;
	if(x>n){
		maxn=max(maxn,sum);
		return;
	}
	dfs(x+1,sum+a[0][x],suma+1,sumb,sumc);
	dfs(x+1,sum+a[1][x],suma,sumb+1,sumc);
	dfs(x+1,sum+a[2][x],suma,sumb,sumc+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int big1=0,big2=0;
		for(int i=1;i<=n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			if(a[1][i]<a[2][i])swap(a[1][i],a[2][i]);
			big1=max(big1,a[1][i]);
			big2=max(big2,a[2][i]);
		}
		if(big2==0){
			if(big1==0){
				sort(a[0]+1,a[0]+n+1);
				int ans=0;
				for(int i=n;i>=n/2;i--)ans+=a[0][i];
				cout<<ans<<"\n";
				continue;
			}
			
		}
		dfs(1,0,0,0,0);
		cout<<maxn<<"\n";
		maxn=0;
	}
	return 0;
}
/*
*/
