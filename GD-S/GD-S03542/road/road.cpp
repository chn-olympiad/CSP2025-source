#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=1e7+233,inf=1e12;
ll n,m,k,cnt,c[20],f[M],ans=inf; 
bool flag=0;
struct Edge{
	ll from,to,v;
}E[M];
bool cmp(Edge x,Edge y){
	return x.v<y.v;
}
void add(int u,int v,ll w){
	E[++cnt].to=v;
	E[cnt].v=w;
	E[cnt].from=u;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
ll ku(int t){
	ll res=0;
	for(int i=1;i<=(n+k);i++)
		f[i]=i;
	for(int i=1,u,v,w,fu,fv;i<=cnt;i++){
		u=E[i].from,v=E[i].to,w=E[i].v;
		if(u>n && !((1<<(u-n-1))&t)) continue;
		if(v>n && !((1<<(v-n-1))&t)) continue;
		fu=find(u);fv=find(v);
		if(fu!=fv){
			f[fv]=fu;
			res+=w;
		}
	}
	return res;
}
ll check(int x){
	ll res=0;
	for(int i=0;i<k;i++)
		if((1<<i)&x) res+=c[i+1];
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	for(int i=1,w;i<=k;i++){
		cin>>c[i];
		if(c[i]) flag=1; 
		for(int j=1;j<=m;j++){
			cin>>w;
			if(w) flag=1;
			add(i+n,j,w);
		}
	}
	sort(E+1,E+1+cnt,cmp);
	if(flag || m<=1e5 || k<=4)
		for(int i=0;i<(1<<k);i++)
			ans=min(ans,ku(i)+check(i));
	else ans=ku((1<<k)-1)+check((1<<k)-1);
	printf("%lld",ans);
	return 0;
}
