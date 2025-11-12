#include<bits/stdc++.h>
using namespace std;
int ma[100005][5];
int n,sum,ans;
int j[5];
void dfs(int x){
	if (x>n){
		ans=max(ans,sum);
		return;
	}
	for (int i=1;i<=3;i++){
		if (j[i]+1<=n/2){
			j[i]++;
			sum+=ma[x][i];
			dfs(x+1);
			sum-=ma[x][i];
			j[i]--;
		}
	}
}
void solve(){
	ans=0;
	sum=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3;j++){
			cin>>ma[i][j];
		}
	}
	dfs(1);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
