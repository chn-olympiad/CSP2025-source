#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10010;
const int M=1100010;
bool pd[13];
ll c[13],a[13][N];
int mi[13];
struct Line{
	int u,v;
	ll val;
	int s;
};
bool operator<(Line x,Line y){
	if(x.val!=y.val)return x.val>y.val;
	if(!x.s)return 1;
	if(!y.s)return 0;
	if(pd[x.s])return 1;
	if(pd[y.s])return 0;
	return c[x.s]<c[y.s];
}
priority_queue<Line>q;
Line mk(int u,int v,ll val,bool s){
	Line re;
	re.u=u;re.v=v;re.val=val;re.s=s;
	return re;
}
int n,m,k;
int he[N];
int find(int x){
	if(he[x]==x)return x;
	return he[x]=find(he[x]);
}
bool merge(int u,int v){
	u=find(u);v=find(v);
	if(u!=v){
		he[u]=v;
		return true;
	}else return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v;i<=m;i++){
		ll val;scanf("%d%d%lld",&u,&v,&val);
		q.push(mk(u,v,val,false)); 
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		a[i][0]=INT_MAX;
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]<a[i][mi[i]])mi[i]=j;
		}
		c[i]+=a[i][mi[i]];
		for(int j=1;j<=n;j++)q.push(mk(mi[i],j,a[i][j]+c[i],i));
	}
	for(int i=1;i<=n;i++)he[i]=i;
	int nu=0;
	ll ans=0;
	while(!q.empty()){
		if(nu==n-1)break;
		int u=q.top().u,v=q.top().v;
		ll val=q.top().val;
		int s=q.top().s;
		q.pop();
		if(merge(u,v)){
			ans+=val;
			if(s&&!pd[s]){
				pd[s]=1;
				for(int i=1;i<=n;i++){
					q.push((mk(mi[s],i,a[s][i],0)));
				}
			}
		}
	}
	printf("%lld\n",ans);
}
/*
15:08 看起来是并查集
15:15 O((m+kn)log(m+kn))
15:27 中文分号都来了 
16:22 操,road4没过
16:40 死机了，重启  
5 4 1
1 2 2
1 3 2
1 4 2
1 5 2
1 1 1 1 1 1
17:09假了! 48pts
但是能过2?大运
操了 诈骗题 
*/
