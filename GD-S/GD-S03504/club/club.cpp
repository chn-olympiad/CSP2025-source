#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,t;
int d[N][4];
int sum[4];
int anss;
void dfs(int x,int ans){
	if(x==n+1){
		anss=max(ans,anss);
		return;
	}
	for(int i=1;i<=3;i++){
		if(sum[i]<n/2){
			sum[i]++;
			dfs(x+1,ans+d[x][i]);
			sum[i]--;
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		anss=0;
		memset(d,0,sizeof(d));
		memset(sum,0,sizeof(sum));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>d[i][j];
			}
		}
		dfs(1,0);
		cout<<anss<<"\n";
	} 
	return 0;
}
