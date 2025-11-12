#include<bits/stdc++.h>
#define int long long
#define MAXN 100005
using namespace std;
int T,n,ans,cnt[5];
struct Node{
	int maxn,sec,lst,a,b,c,va,vb,vc;
}a[MAXN];
struct AC{
	int v,id;
}t[5];
bool cmpt(AC x,AC y){
	return x.v>y.v;
}
bool cmp(Node x,Node y){
	return x.va-x.vb==y.va-y.vb?x.vb-x.vc>y.vb-y.vc:x.va-x.vb>y.va-y.vb;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			t[1].v=a[i].a,t[1].id=1;
			t[2].v=a[i].b,t[2].id=2;
			t[3].v=a[i].c,t[3].id=3;
			sort(t+1,t+3+1,cmpt);
			a[i].maxn=t[1].id,a[i].sec=t[2].id,a[i].lst=t[3].id;
			a[i].va=t[1].v,a[i].vb=t[2].v,a[i].vc=t[3].v;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[a[i].maxn]<n/2){
				cnt[a[i].maxn]++;
				ans+=a[i].va;
			}else if(cnt[a[i].sec]<n/2){
				cnt[a[i].sec]++;
				ans+=a[i].vb;
			}else{
				cnt[a[i].lst]++;
				ans+=a[i].vc;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

