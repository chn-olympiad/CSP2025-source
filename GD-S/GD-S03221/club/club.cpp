#include<bits/stdc++.h>
using namespace std;
int a[1000001][4],t,n,k[4],sum,ans;
void dfs(int x) {
	if(x>n) {
		ans=max(ans,sum);
	} else {
		for(int i=0; i<4; i++) {
			if(k[i]+1>n/2) continue;
			k[i]+=1;
			sum+=a[x][i];
			dfs(x+1);
			k[i]-=1;
			sum-=a[x][i];
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=0; j<3; j++) {
				cin>>a[i][j];
			}
		}
		sum=0;
		ans=-1;
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
