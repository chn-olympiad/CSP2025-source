#include<bits/stdc++.h>
using namespace std;
int flg[100];
long long n,m,k,f[10105],ans=1145141919810114,ffa,ffb,top,head,lsum;
struct road {
	int u,v,flag;
	long long w;
} d[1000005],ld[200005],sd[10005];
struct coun {
	long long c,a[10005];
} ct[20];
int cmp(road A,road B) {
	return A.w<B.w;
}
int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void work(int xx) {
	if(xx<k) {
		xx++;
		flg[xx]=1;
		work(xx);
		flg[xx]=0;
		work(xx);
		return ;
	}
	if(xx==k) {
		for(int i=1; i<=head; i++) {
			ld[i].u=sd[i].u;
			ld[i].v=sd[i].v;
			ld[i].w=sd[i].w;
		}
		top=head;
		lsum=0;
		for(int i=1; i<=k; i++) {
			if(flg[i]==1) {
				lsum+=ct[i].c;
				for(int j=1; j<=n; j++) {
					top++;
					ld[top].u=n+i;
					ld[top].v=j;
					ld[top].w=ct[i].a[j];
				}
			}
		}
		for(int i=1; i<=n+k; i++) f[i]=i;
		sort(ld+1,ld+top+1,cmp);
		for(int i=1; i<=top; i++) {
			ffa=find(ld[i].u);
			ffb=find(ld[i].v);
			if(ffa!=ffb) {
				f[ffa]=ffb;
				lsum+=ld[i].w;
				ld[i].flag=1;
			}
		}
		ans=min(ans,lsum);
		return ;
	}
	return ;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) f[i]=i;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%lld",&d[i].u,&d[i].v,&d[i].w);
	}
	for(int i=1; i<=k; i++) {
		scanf("%lld",&ct[i].c);
		for(int j=1; j<=n; j++) {
			scanf("%lld",&ct[i].a[j]);
		}
	}
	sort(d+1,d+m+1,cmp);
	for(int i=1; i<=m; i++) {
		ffa=find(d[i].u);
		ffb=find(d[i].v);
		if(ffa!=ffb) {
			f[ffa]=ffb;
			ans+=d[i].w;
			d[i].flag=1;
			head++;
			sd[head].u=d[i].u;
			sd[head].v=d[i].v;
			sd[head].w=d[i].w;
		}
	}
	work(0);
	cout<<ans;
	return 0;
}