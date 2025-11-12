#include<bits/stdc++.h>
#define rd read()
#define ll long long
using namespace std;
inline int read()
{
	int x=0,s=getchar();while(s<'0'||s>'9')s=getchar();
	while(s>='0'&&s<='9')x=x*10+s-'0',s=getchar();
	return x;
}
const int N=10015,K=13,M=1000005;
int n,m,g,P,F,k,cnt,ct;ll ans;
int a[K][N],d[K][N],f[N],c[K],G[K],hv[N];
struct red
{
	int x,y,w;
	inline bool operator <(const red &o)const{return w<o.w;}
}t[M],T[N];
struct node
{
	int v,id;
	inline bool operator <(const node &o)const{return v>o.v;}
};priority_queue<node> q;
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void merge(int x,int y){f[find(y)]=find(x);}
inline void clear(){for(int i=1;i<=P;++i)f[i]=i;}
inline bool cmp(int x,int y){return a[g][x]<a[g][y];}
signed main()
{
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	n=rd,m=rd,k=rd,P=n;for(int i=1;i<=m;++i)t[i]={rd,rd,rd};
	for(int i=1;i<=k;++i){c[i]=rd;for(int j=1;j<=n;++j)a[i][j]=rd,d[i][j]=j;}
	for(int i=1;i<=k;++i)g=i,sort(d[i]+1,d[i]+n+1,cmp);sort(t+1,t+m+1),clear();
	for(int i=1;i<=m;++i)
		if(find(t[i].x)!=find(t[i].y))
			merge(t[i].x,t[i].y),T[++cnt]=t[i],ans+=t[i].w;
	int S=(1<<k)-1;ll sum;
	for(int i=1,x,y,w,K,ID;i<=S;++i)
	{
		F=ct=sum=K=0;
		for(int l=1;l<=k;++l)if(i>>(l-1)&1)sum+=c[l],hv[++F]=l;
		P=n+F;if(sum>=ans)continue;clear();
		for(int j=0;j<=F;++j)G[j]=1;q.push({T[1].w,0});
		for(int j=1;j<=F;++j)q.push({a[hv[j]][d[hv[j]][1]],j});
		while(q.size())
		{
			node u=q.top();q.pop();
			if(!u.id){x=T[G[0]].x,y=T[G[0]].y,w=u.v,++G[0];if(G[0]<=cnt)q.push({T[G[0]].w,0});}
			else{ID=hv[u.id],x=n+u.id,y=d[ID][G[u.id]],w=u.v,++G[u.id];if(G[u.id]<=n)q.push({a[ID][d[ID][G[u.id]]],u.id});}
			if(find(x)!=find(y))merge(x,y),++K,sum+=w;if(sum>=ans||K==P-1)break;
		}
		while(q.size())q.pop();ans=min(ans,sum);
	}
	cout<<ans<<'\n';
	return 0;
}
