#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0;
		cin>>n;
		int a[n+1][3],dp[n+1][3];
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
