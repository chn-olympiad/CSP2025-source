//GZ-S00153 贵阳雅礼高级中学（贵阳市第九中学） 张宛钰
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,dp[maxn][5],ans,a1[maxn],a2[maxn],a3[maxn],id[maxn][5];

int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int p;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		p=n/2;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			id[i][1]=a1[i];
			id[i][2]=a2[i];
			id[i][3]=a3[i];
		}
		sort(a1+1,a1+n+1);
		sort(a2+1,a2+n+1);
		sort(a3+1,a3+n+1);
		for(int i=n;i>p;i--) ans+=a1[i];
		cout<<ans<<endl;
	}
	
	return 0;
}
