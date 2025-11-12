#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,m_,k,a[20][N],c[20],f[N+20];
ll ans;
struct edge{
	int u,v,w;
}E[M],E2[M],E3[N];
bool operator<(edge x,edge y){
	return x.w>y.w;
}
inline int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
priority_queue<edge>q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
		q.push(E[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	int cnt=0;
	while(cnt<n-1){
		int u=q.top().u,v=q.top().v,w=q.top().w;
		E2[++m_]=q.top();q.pop();
		if(find(u)!=find(v)){
			f[find(u)]=find(v);
			ans+=w;cnt++;
		}
	}
	while(q.top().w==E2[m_].w){
		E2[++m_]=q.top();q.pop();
	}
	m=m_;
	for(int i=1;i<=m;i++)E[i]=E2[i];
	for(int S=1;S<(1<<k);S++){
		for(int i=1;i<=n;i++)f[i]=i;
		ll ret=0;m_=0;
		for(int i=1;i<=k;i++){
			if(S&(1<<(i-1))){
				ret+=c[i];
				for(int j=1;j<=n;j++){
					E3[j]=(edge){0,j,-a[i][j]};
				}
				sort(E3+1,E3+n+1);
				ret+=-E3[1].w;
				for(int j=2;j<=n;j++){
					E2[++m_]=E3[j];
					E2[m_].u=E3[1].v;
				}
			}
		}
		sort(E2+1,E2+m_+1);
		cnt=0;int i1=1,i2=1;
		while(cnt<n-1){
			int u,v,w;
			if(i1>m){
				u=E2[i2].u,v=E2[i2].v,w=-E2[i2].w;
				i2++;
			}
			else if(i2>m_){
				u=E[i1].u,v=E[i1].v,w=E[i1].w;
				i1++;
			}else if(E[i1].w<-E2[i2].w){
				u=E[i1].u,v=E[i1].v,w=E[i1].w;
				i1++;
			}else{
				u=E2[i2].u,v=E2[i2].v,w=-E2[i2].w;
				i2++;
			}
			if(find(u)!=find(v)){
				f[find(u)]=find(v);
				ret+=w;cnt++;
			}
		}
		ans=min(ans,ret);
	}
	cout<<ans;
	return 0;
}
