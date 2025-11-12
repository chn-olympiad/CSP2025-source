#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,a[N][4],cnt1,cnt2,cnt3,d[N],vis[N],f,ans; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;cnt1=0;cnt2=0;cnt3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]) cnt1++,vis[i]=1;
			else if(a[i][2]>a[i][3]) cnt2++,vis[i]=2;
			else cnt3++,vis[i]=3;
			ans+=a[i][vis[i]];
		}
		if(cnt1>cnt2&&cnt1>cnt3) f=1;
		else if(cnt2>cnt3) f=2;
		else f=3;
		int cnt=max(cnt1,max(cnt2,cnt3));
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			printf("%d\n",ans);continue;
		}
		for(int i=1;i<=n;i++){
			d[i]=1e9;
			if(vis[i]!=f) continue;
			for(int j=1;j<=3;j++) if(j!=f )d[i]=min(d[i],a[i][f]-a[i][j]);
		}
		sort(d+1,d+n+1);
		for(int i=1;i<=n;i++){
			ans-=d[i];cnt--;
			if(cnt<=n/2) break;
		}
		printf("%d\n",ans);
	}

	return 0;
} 
