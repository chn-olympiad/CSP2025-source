#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//前i个 考虑第j组 k 0=最大值，>0=该组已选人数 
/*
if(j!=k){
	f[i][j][k]=f[i-1][k][j]+1,f[i][j][0]=max(f[i][j][0],f[i-1][k][0]);
}else if(f[i-1][k][k]<n/2){
	f[i][k][k]=f[i-1][k][k]+1
}
*/
ll t,n,ans=0,a[100010][4];
void dfs(ll x,ll sum,ll a1,ll a2,ll a3){
	if(x==n){
		ans=max(ans,sum);
		return;
	}
	if(a1<n/2)
		dfs(x+1,sum+a[x+1][1],a1+1,a2,a3);
	if(a2<n/2)
		dfs(x+1,sum+a[x+1][2],a1,a2+1,a3);
	if(a3<n/2)
		dfs(x+1,sum+a[x+1][3],a1,a2,a3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=3;j++)
				cin>>a[i][j];
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
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
