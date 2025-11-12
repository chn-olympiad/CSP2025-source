#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100100;
int t,n,a[N][4],ans;
void dfs(int i,int sum,int l1,int l2,int l3){
	if(i>n){
		ans=max(ans,sum);
		return;
	}
	if(l1<n/2) dfs(i+1,sum+a[i][1],l1+1,l2,l3);
	if(l2<n/2) dfs(i+1,sum+a[i][2],l1,l2+1,l3);
	if(l3<n/2) dfs(i+1,sum+a[i][3],l1,l2,l3+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++) cin>>a[i][j];
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	fcloseall();
	return 0;
}
//约40pts
//
