#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second 
#define mp make_pair
int in(){
	int a=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())a=(a<<1)+(a<<3)+c-'0';
	return a*f;
}
const int N=1e4+11,M=1e6+1e5+7;
int n,m,k;
struct ed{
	int v,w,nex;
}edge[M*2];
int cnt=0,head[N];
void add(int u,int v,int w){
	cnt++;
	edge[cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].nex=head[u];
	head[u]=cnt;
}
bool b[N];
void lst(int fr){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	int ans=0;
	q.push(mp(0,fr));
	memset(b,0,sizeof(b));
	int tmp;
	while(!q.empty()){
		ans+=q.top().x;
		tmp=q.top().y;
		b[tmp]=1;
		q.pop();
		for(int i=head[tmp];i;i=edge[i].nex){
			if(!b[edge[i].v]){
				q.push(mp(edge[i].w,edge[i].v));
			}
		}
		while(!q.empty()&&b[q.top().y])q.pop();
	}
	cout<<ans<<'\n';
}
int cst[11];
void ls2(int fr){
	priority_queue<pair<int,pii>,vector<pair<int,pii> >,greater<pair<int,pii> > > q;
	int ans=0;
	q.push(mp(0,mp(fr,fr)));
	memset(b,0,sizeof(b));
	int tmp;
	int cnt[11]={};
//	for(int i=1;i<=k;i++)ans+=cst[i];
	while(!q.empty()){
		ans+=q.top().x;
		tmp=q.top().y.x;
		if(tmp>n)cst[tmp-n]+=q.top().x;
		if(q.top().y.y>n)cnt[q.top().y.y-n]++;
		b[tmp]=1;
		q.pop();
		for(int i=head[tmp];i;i=edge[i].nex){
			if(!b[edge[i].v]){
				q.push(mp(edge[i].w,mp(edge[i].v,tmp)));
			}
		}
		while(!q.empty()&&b[q.top().y.x])q.pop();
	}
	for(int i=1;i<=k;i++){
		if(cnt[i]==0)ans-=cst[i];
	}
	cout<<ans<<'\n';
}
void ls3(int fr){
	priority_queue<pair<int,pii>,vector<pair<int,pii> >,greater<pair<int,pii> > > q;
	int ans=0;
	q.push(mp(0,mp(fr,fr)));
	memset(b,0,sizeof(b));
	int tmp;
	int cnt[11]={};
	for(int i=1;i<=k;i++)ans+=cst[i];
	while(!q.empty()){
		ans+=q.top().x;
		tmp=q.top().y.x;
		if(tmp>n)cst[tmp-n]+=q.top().x;
		if(q.top().y.y>n)cnt[q.top().y.y-n]++;
		b[tmp]=1;
		q.pop();
		for(int i=head[tmp];i;i=edge[i].nex){
			if(!b[edge[i].v]){
				q.push(mp(edge[i].w,mp(edge[i].v,tmp)));
			}
		}
		while(!q.empty()&&b[q.top().y.x])q.pop();
	}
	for(int i=1;i<=k;i++){
		if(cnt[i]==0)ans-=cst[i];
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in();m=in();k=in();
	int u,v,w;
	for(int i=1;i<=m;i++){
		u=in();v=in();w=in();
		add(u,v,w);
		add(v,u,w);
	}
	if(k==0){
		lst(1);
	}else{
		for(int i=1;i<=k;i++){
			u=i+n;
			cst[i]=in();
			for(int j=1;j<=n;j++){
				w=in();
				add(u,j,w);
				add(j,u,w);
			}
		}
		if(cst[1]==0)ls2(1);
		else{
			ls3(1);
		}
	}
	return 0;
}/*
4 6 0
1 2 5
1 3 5
1 4 5
2 3 2
2 4 6
3 4 1

*/
