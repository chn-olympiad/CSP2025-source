#include<bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;

const int N=5e3+5;
int n;
struct aox{
	int x,id;
}a[N];
bool vis[N];
int cnt;

void dfs(int prev,int now,int mx,int sum,int m){
	int i,j;
	for(i=prev+1;i<=n;i++){
		dfs()
	}
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	
	dfs(0,1,-1,0,0);
	
	cout<<cnt%MOD;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}