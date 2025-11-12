#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,a[4][N],ans;
void dfs(int sum,int pos,int n1,int n2,int n3){
	if(pos==n+1){
		ans=max(ans,sum);
		return;
	} 
	if(n1<=n/2) dfs(sum+a[1][pos],pos+1,n1+1,n2,n3);
	if(n2<=n/2) dfs(sum+a[2][pos],pos+1,n1,n2+1,n3);
	if(n2<=n/2) dfs(sum+a[3][pos],pos+1,n1,n2,n3+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[1][i]>>a[2][i]>>a[3][i];
		dfs(0,1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}


