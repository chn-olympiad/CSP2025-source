#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,M=3e6+10,INF=1e14+10;
int n,m,k;
int h[N],e[M*2],w[M*2],ne[M*2],idx;
inline int read(){
	int w=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9') w=w*10+ch-'0',ch=getchar();
	return f*w;
}
void add(int a,int b,int c){
	idx++;
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx;
}
void del(int a){
	h[a]=ne[idx];
	idx--;
}
int a[11][N],b[11][N];
int ans=INF;
int dist[N],st[N];
int c[N];
int prim1(int s,int m){
	for(int i=1;i<=n+k;i++) dist[i]=INF;
	st[s]=1,dist[s]=0;
	for(int i=h[s];i;i=ne[i]){
//		cout<<;
		dist[e[i]]=min(dist[e[i]],w[i]+((e[i]>n&&!st[e[i]])?c[e[i]-n]:0));
//		cout<<e[i]<<' '<<dist[e[i]]<<endl;
	}
	int cnt=1;
	int res=0;
	while(cnt<m){
		int mx=INF,t=-1;
		int flag=1;
		for(int i=1;i<=n;i++) flag&=st[i];
		if(flag) break;
		for(int i=1;i<=n+k;i++){
			if(st[i]==1) continue;
			if(dist[i]<mx) mx=dist[i],t=i;
		}
		st[t]=1;
//		cout<<"t:"<<t<<endl;
		res+=mx;
		if(res>ans) return ans;
		bool flat=false;
		for(int i=h[t];i;i=ne[i]){
//			cout<<e[i]<<endl;
			if(w[i]+((e[i]>n&&!st[e[i]])?c[e[i]-n]:0)<dist[e[i]]) flat=true,dist[e[i]]=w[i]+((e[i]>n&&!st[e[i]])?c[e[i]-n]:0);
		}
		if(!flat&&t>n) res-=mx;
		cnt++;
	}
//	cout<<"H\n";
	return res; 
}
int prim2(int s,int m){
	for(int i=1;i<=n+k;i++) dist[i]=INF;
	st[s]=1,dist[s]=0;
	for(int i=h[s];i;i=ne[i]){
		dist[e[i]]=min(dist[e[i]],w[i]);
	}
	int cnt=1;
	int res=0;
	while(cnt<m){
		int mx=INF,t=-1;
		for(int i=1;i<=n+k;i++){
			if(st[i]==1) continue;
			if(dist[i]<mx) mx=dist[i],t=i;
		}
		st[t]=1;
//		cout<<"t:"<<t<<endl;
		res+=mx;
		if(res>ans) return ans;
		for(int i=h[t];i;i=ne[i]){
			dist[e[i]]=min(dist[e[i]],w[i]);
		}
		cnt++;
	}
//	cout<<"H\n";
	return res; 
}
void so1(){
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			add(i+n,j,a[i][j]);
			add(j,i+n,a[i][j]);
		}
	}
	ans=prim1(1,n+k);
	cout<<ans;
}
void so2(){
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			add(i+n,j,a[i][j]);
			add(j,i+n,a[i][j]);
			st[i+n]=1;
		}
	}
	ans=prim2(1,n);
//	cout<<ans<<endl;
	for(int i=1;i<(1<<k);i++){
		int res=0;
		for(int i=1;i<=n+k;i++) st[i]=0; 
		for(int j=1;j<=k;j++){
			if((i>>(j-1)&1)==0) st[j+n]=1;
			else res+=c[j];
		}
		int ex=__builtin_popcount(i);
		if(res>ans) continue;
		int r=res+prim2(1,ex+n);
//		cout<<r<<endl;
		ans=min(ans,r);
	} 
	cout<<ans;
}
signed main(){
//	freopen("road3.in","r",stdin);
//	freopen("road2.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	if(n*n*(1<<k)>1e8) so1();
	else so2();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
