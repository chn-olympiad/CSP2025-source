#include<bits/stdc++.h>
#define int long long
#define PYY pair<int,int>
#define x first
#define y second
using namespace std;
const int N=1e5+1;
int T,n,a[N][4],b[5],ps;//呜呜呜我要回家打洲
void dfs(int k,int ans){
	if(k==n+1){
		ps=max(ps,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(b[i]+1<=n/2){
			++b[i]; 
			dfs(k+1,ans+a[k][i]);
			--b[i];
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		ps=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,0);
		cout<<ps<<'\n';
	}
	return 0;
}

