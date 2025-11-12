#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int a[maxn][5],b[maxn],ga[maxn],gb[maxn],gc[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		ll ans=0; int cnta=0,cntb=0,cntc=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) ans+=a[i][1],ga[++cnta]=i;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) ans+=a[i][2],gb[++cntb]=i;
			else ans+=a[i][3],gc[++cntc]=i;
		}
		int n2=n/2;
		if(cnta>n2){
			for(int i=1;i<=cnta;i++)
				b[i]=min(a[ga[i]][1]-a[ga[i]][2],a[ga[i]][1]-a[ga[i]][3]);
			sort(b+1,b+cnta+1);
			for(int i=1;i<=cnta-n2;i++)
				ans-=b[i];
		}
		else if(cntb>n2){
			for(int i=1;i<=cntb;i++)
				b[i]=min(a[gb[i]][2]-a[gb[i]][1],a[gb[i]][2]-a[gb[i]][3]);
			sort(b+1,b+cntb+1);
			for(int i=1;i<=cntb-n2;i++)
				ans-=b[i];
		}
		else if(cntc>n2){
			for(int i=1;i<=cntc;i++)
				b[i]=min(a[gc[i]][3]-a[gc[i]][1],a[gc[i]][3]-a[gc[i]][2]);
			sort(b+1,b+cntc+1);
			for(int i=1;i<=cntc-n2;i++)
				ans-=b[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
