#include<iostream>
#include<cstdio>
using namespace std;
int n,a[200002][4];
int res=0;
int dfs(int r,int ak,int bk,int ck,int data){
	if(r==n)res=max(res,data);
	if(ak<n/2)dfs(r+1,ak+1,bk,ck,data+a[r+1][1]);
	if(bk<n/2)dfs(r+1,ak,bk+1,ck,data+a[r+1][2]);
	if(ck<n/2)dfs(r+1,ak,bk,ck+1,data+a[r+1][3]);
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	long long as;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		res=0;
		dfs(1,1,0,0,a[1][1]);
		dfs(1,0,1,0,a[1][2]);
		dfs(1,0,0,1,a[1][3]);
		cout<<res<<'\n';
	}
	return 0;
}

