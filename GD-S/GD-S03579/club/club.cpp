#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,ans=0;
bool f1=false;
int kkk[N+5],cnt=0;
struct p {
	int group;
	int v;
	int belong;
};
struct s {
	p aa[5];
	int k=1;
} a[N+5];
bool cmp(p x,p y) {
	return x.v>y.v;
}
bool operator < (const p &x,const p &y) {
	return x.v>y.v;
}
priority_queue<p> que[5];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&a[i].aa[1].v,&a[i].aa[2].v,&a[i].aa[3].v);
			if(a[i].aa[2].v!=0||a[i].aa[3].v!=0) f1=true;
			kkk[++cnt]=a[i].aa[1].v;
			a[i].aa[1].group=1,a[i].aa[2].group=2,a[i].aa[3].group=3;
			a[i].aa[1].belong=i,a[i].aa[2].belong=i,a[i].aa[3].belong=i;
			sort(a[i].aa+1,a[i].aa+4,cmp);
		}
		if(f1==false) {
			sort(kkk+1,kkk+cnt+1);
			for(int i=cnt;i>n/2;i--) ans+=kkk[i];
			printf("%d\n",ans);
			f1=false;
			cnt=0;
			continue;
		}
		for(int i=1;i<=n;i++) {
			if(que[a[i].aa[a[i].k].group].size()==n/2) {
//				cout<<i<<" ";
				p t=que[a[i].aa[a[i].k].group].top();
				if(ans-t.v+a[i].aa[a[i].k].v+a[t.belong].aa[a[t.belong].k+1].v>ans+a[i].aa[a[i].k+1].v) {
					que[a[i].aa[a[i].k].group].pop();
					que[a[i].aa[a[i].k].group].push({a[i].aa[a[i].k].group,a[i].aa[a[i].k].v,a[i].aa[a[i].k].belong});
					que[a[t.belong].aa[a[t.belong].k+1].group].push({a[t.belong].aa[a[t.belong].k+1].group,a[t.belong].aa[a[t.belong].k+1].v,a[t.belong].aa[a[t.belong].k+1].belong});
					ans=ans-t.v+a[i].aa[a[i].k].v+a[t.belong].aa[a[t.belong].k+1].v;
					a[t.belong].k++;
				} else {
					que[a[i].aa[a[i].k+1].group].push({a[i].aa[a[i].k+1].group,a[i].aa[a[i].k+1].v,a[i].aa[a[i].k+1].belong});
					ans+=a[i].aa[a[i].k+1].v;
					a[i].k++;
				}
			} else {
				que[a[i].aa[a[i].k].group].push({a[i].aa[a[i].k].group,a[i].aa[a[i].k].v,a[i].aa[a[i].k].belong});
				ans+=a[i].aa[a[i].k].v;
			}
		}printf("%d\n",ans);
	}
	
}
