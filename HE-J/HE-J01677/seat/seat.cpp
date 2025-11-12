#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+100;
int n,m;
int a[N];
bool vis[300][300];
int mp[300][300];
int dx[3]={1,-1};
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int y,int k,int op){
	vis[x][y]=1;mp[x][y]=a[op];
	if(!vis[x][y+1]&&x==1&&y+1<=m&&k==0){
		dfs(x,y+1,1,op+1);
	}
	if(!vis[x][y+1]&&x==n&&y+1<=m&&k==0){
		dfs(x,y+1,1,op+1);
	}
	for(int i=0;i<2;i++){
		int tx=x+dx[i];
		if(!vis[tx][y]&&tx<=n&&tx>=1){
			dfs(tx,y,0,op+1);
		}
		
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int p=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m,cmp);
	dfs(1,1,1,1); 
	int x,y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==p){
				x=i;y=j;
				break;
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
