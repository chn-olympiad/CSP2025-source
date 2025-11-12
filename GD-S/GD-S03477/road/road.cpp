#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define ll int
#define ri register int
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
inline ll read(){
	ll r=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		r=(r<<1)+(r<<3)+(c^48);
		c=getchar();
	}
	return r*f;
}
inline ll Min(ll a,ll b){
	return a<b?a:b;
}
inline ll Max(ll a,ll b){
	return a>b?a:b;
}
const int N=1e5+5;
struct edge{
	int x,y,z;
	bool operator<(const edge &k)const{
		return z<k.z;
	}
}q[N];
struct edge2{
	int x,y,z;
	bool operator<(const edge2 &k)const{
		return z>k.z;
	}
}s[N];
ll n,m,k;
#define mk make_pair
ll f[N],ans=0;
inline int find(int x){
	if(x==f[x]) return x;
	return find(f[x]);
}
vector<int>g[N];
vector<pair<int,int> >V[N];
priority_queue<int>ANS;
inline void change(int x,int y){
	int js=0,js1=0;
	f[x]=x;
	js=n-1-V[x].size();
	memset(q,0,sizeof q);
	for(int i=1;i<=n;i++){
		q[i].x=x;
		q[i].y=i;
		q[i].z=g[y][i];
	}
	for(auto k:V[x]) js1-=k.second;
	sort(q+1,q+1+n);
	for(int i=1;i<=n;i++){
		int fx=find(q[i].x),fy=find(q[i].y);
		if(fx!=fy){
			f[x]=y;
			js++;
			js1+=q[i].z;
		}
		if(js==n-1) break;
	}
	js1+=g[y][0];
	if(js1<0) ANS.push(-1*(ans+js1));
	
}
int js=0,js1=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		q[i].x=read(),q[i].y=read(),q[i].z=read();
	for(int i=1;i<=n;i++) f[i]=i;
	sort(q+1,q+1+n);
	for(int i=1;i<=m;i++){
		int fx=find(q[i].x),fy=find(q[i].y);
		if(fx!=fy){
			f[q[i].x]=q[i].y;
			js++;
			edge2 d;
			d.x=q[i].x,d.y=q[i].y,d.z=q[i].z;
			s[js]=d;
			ans+=q[i].z;
			V[q[i].x].push_back(mk(q[i].y,q[i].z));
			V[q[i].y].push_back(mk(q[i].x,q[i].z));
		}
		if(js==n-1) break;
	}
	for(int i=1;i<=k;i++){
		int x=read(),y;
		g[i].push_back(x);
		for(int j=1;j<=n;j++){
			y=read();
			g[i].push_back(y+x);
		}
	}
	sort(s+1,s+1+js);
	for(int i=1;i<=js;i++)
		change(i,1);
	write(-1*(ANS.top()));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
