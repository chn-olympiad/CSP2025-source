#include <bits/stdc++.h>
using namespace std;
long long c[15][2000005];
struct node{
	long long u,v,w;
}b[2000005],h[2000005];
priority_queue<pair<long long,pair<long long,long long> >,vector<pair<long long,pair<long long,long long> > >,greater<pair<long long,pair<long long,long long> > > >q;
long long fa[2000005];
long long find(long long x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void update(long long x,long long y){
	long long xx=find(x);
	long long yy=find(y);
	fa[yy]=xx;
}
long long p[2000005];
long long del[2000005];
long long in[2000005];
int main(){
//	freopen("road4.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	scanf ("%lld%lld%lld",&n,&m,&k);
	for (long long i=1;i<=m;++i){
		long long u,v,w;
		scanf ("%lld%lld%lld",&u,&v,&w);
		b[i]=(node){u,v,w};
	}
	for (long long i=1;i<=k;++i)
		for (long long j=0;j<=n;++j)
			scanf("%lld",&c[i][j]);
	long long ans=0;
	while (!q.empty())
		q.pop();
	long long len=0;
	/*
	for (int i=0;i<k;++i)
		if ((s&p[i])==(p[i])){
			for (int j=1;j<=n;++j)
				q.push(make_pair(c[i][j],make_pair(j,n+kk+1)));
			js+=c[i][0];
			kk++;
		}*/
	for (long long i=1;i<=n;++i)
		fa[i]=i;
	for (long long i=1;i<=m;++i)
		q.push(make_pair(b[i].w,make_pair(b[i].u,b[i].v)));
	long long o=0;
	while (!q.empty()){
		if (o==n-1)
			break;
		long long u,v,w;
		u=q.top().second.first;
		v=q.top().second.second;
		w=q.top().first;
		q.pop();
		if (find(u)!=find(v)){
			update(u,v);
			o++;
			ans+=w;
			b[++len]=(node){u,v,w};
		}
	}
/*	printf ("%d\n",ans);
	for (int i=1;i<=len;++i)
		printf ("%d %d\n",b[i].u,b[i].v);
	printf("No%d______________________\n",0);*/
	long long sss=0,ssss=0;
	for (long long s=k;s>=1;--s){
		memset(in,0,sizeof(in));
		long long lens=0;
		long long js=c[s][0]+ssss;
		for (long long i=1;i<=n+sss+1;++i)
			fa[i]=i;
		while (!q.empty())
			q.pop();
		for (long long j=1;j<=n;++j){
			q.push(make_pair(c[s][j],make_pair(j,n+sss+1)));
//			printf ("%d %d [%d]\n",n+1,j,c[s][j]);
		}
		for (long long i=1;i<=m;++i){
			if (del[b[i].u] || del[b[i].v]){
				continue;
			}
			q.push(make_pair(b[i].w,make_pair(b[i].u,b[i].v)));
		}
		long long o=0;
		while (!q.empty()){
			if (o==n+sss)
				break;
			long long u,v,w;
			u=q.top().second.first;
			v=q.top().second.second;
			w=q.top().first;
//			printf ("%d %d %d\n",u,v,w);
			q.pop();
			if (find(u)!=find(v)){
				update(u,v);
				o++;
				js+=w;
				in[u]++;
				in[v]++;
				h[++lens]=(node){u,v,w};
			}
		}
		/*
		printf ("%lld\n",js);
		for (int i=1;i<=k;++i)
			printf ("%d %d\n",in[p[i]],p[i]);
		printf("No%lld______________________\n",s);*/
		/*for (long long i=1;i<=k;++i){
			if (in[p[i]]==1){
				js-=c[p[i]][0];
				p[i]=0;
		//		sss--;
		//		del[p[i]]=1;
			}
		}*/
		if (js<ans){
			for (long long i=1;i<=lens;++i)
				b[i]=h[i];
			ssss+=c[s][0];
			ans=js;
			p[s]=sss;
			sss++;
		}
	}
	printf ("%lld",ans);
	return 0;
}
