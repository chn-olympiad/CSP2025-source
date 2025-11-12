#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005],ans;
void dfs(int pos,int sum,int maxn,int choice){
	if(pos==n+1){
		if(sum>2*maxn&&choice>=3) ans=(ans+1)%998244353;
		return;
	}
	dfs(pos+1,sum+a[pos],max(maxn,a[pos]),choice+1);
	dfs(pos+1,sum,maxn,choice);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0;
}
