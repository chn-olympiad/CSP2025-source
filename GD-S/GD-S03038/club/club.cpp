#include<bits/stdc++.h>
#define N 202
#define pr pair<double,int>
#define fir first
#define sec second
using namespace std;
int t,n,a[N][4],sum[4],mn;
int f[N][N][N];
void dfs(int x){
	f[x][sum[1]][sum[2]]=0;
	if(x<=n){
		if(f[x+1][sum[1]+1][sum[2]]==-1&&sum[1]<mn){
			sum[1]++;
			dfs(x+1);
			sum[1]--;
		}
		if(f[x+1][sum[1]][sum[2]+1]==-1&&sum[2]<mn){
			sum[2]++;
			dfs(x+1);
			sum[2]--;
		}
		if(f[x+1][sum[1]][sum[2]]==-1&&sum[3]<mn){
			sum[3]++;
			dfs(x+1);
			sum[3]--;
		}
		if(sum[1]<mn) f[x][sum[1]][sum[2]]=max(f[x+1][sum[1]+1][sum[2]]+a[x][1],f[x][sum[1]][sum[2]]);
		if(sum[2]<mn) f[x][sum[1]][sum[2]]=max(f[x+1][sum[1]][sum[2]+1]+a[x][2],f[x][sum[1]][sum[2]]);
		if(sum[3]<mn) f[x][sum[1]][sum[2]]=max(f[x+1][sum[1]][sum[2]]+a[x][3],f[x][sum[1]][sum[2]]);
	}
	return ;
}
int main(){
	//freopen("club4.in","r",stdin);
	//freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(;t>=1;t--){
		memset(f,-1,sizeof(f));
		cin>>n;
		mn=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1);
		cout<<f[1][0][0]<<"\n";
	}
	return 0;
}
