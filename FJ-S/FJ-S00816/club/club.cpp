#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
int a[100100][10];
int st[10];
int maxx,mx;
int n;
void dfs(int idx,int ans){
	if(idx==n+1){
		mx=max(mx,ans);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(st[i]<maxx){
			st[i]++;
			dfs(idx+1,ans+a[idx][i]);
			st[i]--;
		}
	}
}
void solve(){
	mx=-inf;
	for(int i=1;i<=3;i++)st[i]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	maxx=n/2;
	dfs(1,0);
	cout<<mx<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
