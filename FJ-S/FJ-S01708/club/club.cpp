#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans=0,a[N][5];
void dfs(int now,int x,int y,int z,int sum){
	if(now==n+1){
		ans=max(ans,sum);
		return;
	}
	if(x+1<=n/2)dfs(now+1,x+1,y,z,sum+a[now][1]);
	if(y+1<=n/2)dfs(now+1,x,y+1,z,sum+a[now][2]);
	if(z+1<=n/2)dfs(now+1,x,y,z+1,sum+a[now][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
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
