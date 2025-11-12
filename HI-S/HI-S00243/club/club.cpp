#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int N = 1e5+2;
int T,n,mans = -1;
int a[N][4];
void dfs(int u,int x,int y,int z,int s){
	if(x>n/2||y>n/2||z>n/2)return ;
	if(u==n+1){
		mans = max(mans,s);
		return ;
	}
	dfs(u+1,x+1,y,z,s+a[u][0]);
	dfs(u+1,x,y+1,z,s+a[u][1]);
	dfs(u+1,x,y,z+1,s+a[u][2]);
}
void solve(){
	mans = -1;
	int mmx = -1;
	cin>>n;
	fr(i,1,n){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		mmx = max(a[i][1],max(a[i][2],mmx));
	}
	if(mmx==0){
		int aa[100002],dan = 0;
		fr(i,1,n)aa[i] = a[i][0];
		sort(aa+1,aa+n+1);
		for(int i=n;i>=n/2;i--)dan+=aa[i];
		cout<<dan<<"\n";
		return ;
	}
	if(n<=10){
		dfs(1,0,0,0,0);
		cout<<mans<<"\n";
		return ;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)solve();
	return 0;
}

