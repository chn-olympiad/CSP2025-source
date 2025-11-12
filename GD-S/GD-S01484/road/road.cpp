#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int BUF=1<<20;
char buf[BUF],*p1=buf,*p2=buf;
inline char gc(){
	if(p1==p2)p2=(p1=buf)+fread(buf,1,BUF,stdin);
	return p1==p2?EOF:*p1++;
}
template<class T=int>T read(T&&x=0){
	int f=1;
	x=0;
	char ch=gc();
	while(!isdigit(ch))f-=(ch=='-')<<1,ch=gc();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return x;
}
const int N=1e4+5,M=1e6+5,K=15;
int s[N+K];
int find(int x){
	return s[x]==x?x:s[x]=find(s[x]);
}
struct edg{
	int u,v,w;
	friend bool operator<(edg lhs,edg rhs){
		return lhs.w<rhs.w;
	}
}e0[M],e[N],ne[K][N],ee[N*K];
int c[K];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		e0[i]={read(),read(),read()};
	}
	sort(e0+1,e0+m+1);
	for(int i=1;i<=n;i++)s[i]=i;
	ll cur=0,sum=0;
	for(int i=1;i<=m;i++){
		int x=find(e0[i].u),y=find(e0[i].v),w=e0[i].w;
		if(x==y)continue;
		e[++cur]=e0[i];
		sum+=w;
		s[y]=x;
	}
	ll ans=sum;
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			ne[i][j]={i+n,j,read()};
		}
		sort(ne[i]+1,ne[i]+n+1);
	}
	for(int i=1;i<n;i++)ne[k+1][i]=e[i];
	ne[k+1][n]={1,1,(int)1e9+7};
	for(int bas=1;bas<(1<<k);bas++){
		ll tmp=0;
		vector<int>cun,cur;
		for(int i=0;i<k;i++)if(bas&(1<<i))cun.push_back(i+1),cur.push_back(0),tmp+=c[i+1];
		cun.push_back(k+1),cur.push_back(0);
		for(int i=1;i<=n+k;i++)s[i]=i;
		int len=0,bian=0;
		while(len<(cun.size()+1)*n&&bian<n+cun.size()-2){
			edg minn={1,1,(int)1e9+7};
			int ps=0;
			for(int i=0;i<cun.size();i++)if(cur[i]<n){
				if(ne[cun[i]][cur[i]+1]<minn)minn=ne[cun[i]][cur[i]+1],ps=i;
			}
			cur[ps]++,len++;
			int x=find(minn.u),y=find(minn.v),w=minn.w;
			if(x==y)continue;
			bian++;
			s[x]=y;
			tmp+=w;
		}
		ans=min(ans,tmp);
	}
	cout<<ans;
}
