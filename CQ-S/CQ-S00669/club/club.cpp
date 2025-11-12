#include <bits/stdc++.h>
using namespace std;
namespace lyj{
	int T;
	const int N=1e5+5;
	int n,ans[4];
	struct node{
		int a[3],id[3];
	}p[N];
	bool cmp0(node x,node y){return x.a[0]>y.a[0];}
	bool cmp1(node x,node y){return x.a[1]>y.a[1];}
	bool cmp2(node x,node y){return x.a[2]>y.a[2];}
	bool cmp3(node x,node y){return max(x.a[0],max(x.a[1],x.a[2]))>max(y.a[0],max(y.a[1],y.a[2]));}
	void solve(){
		memset(ans,0,sizeof(ans));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				scanf("%d",&p[i].a[j]);
			}
		}sort(p+1,p+n+1,cmp0);
		for(int i=1;i<=n/2;i++)ans[0]+=p[i].a[0];
		for(int i=n/2+1;i<=n;i++)ans[0]+=max(p[i].a[1],p[i].a[2]);
		sort(p+1,p+n+1,cmp1);
		for(int i=1;i<=n/2;i++)ans[1]+=p[i].a[1];
		for(int i=n/2+1;i<=n;i++)ans[1]+=max(p[i].a[0],p[i].a[2]);
		sort(p+1,p+n+1,cmp2);
		for(int i=1;i<=n/2;i++)ans[2]+=p[i].a[2];
		for(int i=n/2+1;i<=n;i++)ans[2]+=max(p[i].a[0],p[i].a[1]);
		sort(p+1,p+n+1,cmp3);int cnt[3]={0,0,0};
		for(int i=1;i<=n;i++){
			int pos,maxn=-1,secn=-1;
			for(int j=0;j<=2;j++){if(p[i].a[j]>=maxn){secn=maxn;maxn=p[i].a[j];pos=j;}}
			if(cnt[pos]<n/2){cnt[pos]++;ans[3]+=maxn;}else{ans[3]+=secn;}
		}
		sort(ans,ans+4);
		printf("%d\n",ans[3]);
	}
	int main(){
		scanf("%d",&T);
		while(T--){solve();}
		return 0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	lyj::main();return 0;
}/*What a great failure?!
AFO is waving to me!*/

