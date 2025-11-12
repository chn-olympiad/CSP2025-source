#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,g[1<<20],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(g,-0x3f,sizeof(g));
	cin>>n>>k;
	int m=0;
	g[0]=0;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		m^=t;
		g[m]=max(g[m^k]+1,g[m^t]);
		ans=max(g[m],ans);
	}
	cout<<ans;
	return 0;
}