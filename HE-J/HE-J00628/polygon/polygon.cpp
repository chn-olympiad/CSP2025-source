#include <bits/stdc++.h>
using namespace std;
int n;
int a[110000],ans,b[110000],ma;
bool vis[110000];
void dfs(int step,int sum){
	
	if(step>=4&&sum>ma*2){
//		for(int i=1;i<step;i++){
//			cout<<b[i]<<' ';
//		}
//		cout<<'\n';

		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		b[step]=a[i];
		vis[i]=1;
		if(step>=2)ma=max(b[step],ma);
		else ma=b[step];
		dfs(step+1,sum+b[step]);
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in", "r",stdin);
	freopen("polygon.out", "w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	dfs(1,0);
	cout<<ans/12;
	return 0;
}
