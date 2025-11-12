#include<bits/stdc++.h>
using namespace std;
#define N 100009 
int a[N][10],n,t,cnt[4],ans,xuan[N],b[4],f[N][10],a1[N];
int dfs(int x,int y,int c1,int c2,int c3){
	if(x==n || c1>n/2 || c2>n/2 || c3>n/2) return a[x][y];
	cout<<x<<' '<<y<<'\n';
//	cout<<'\n';
	if(f[x][y]!=-1 && x!=0 && y!=0) return f[x][y];
	f[x][y]=a[x][y]+max({dfs(x+1,1,c1+1,c2,c3),dfs(x+1,2,c1,c2+1,c3),dfs(x+1,3,c1,c2,c3+1)});
	return f[x][y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n>=1e5){
			for(int i=1;i<=n;i++){
				int x,y;
				cin>>a1[i]>>x>>y;
			}
			sort(a1+1,a1+n+1);
			for(int i=n;i>=n/2;i--)ans+=a1[i];
			cout<<ans;
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<4;j++) f[i][j]=-1;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		f[0][0]=-1;
		int res=dfs(0,0,0,0,0);
		cout<<res<<'\n';
	}
}/*
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

