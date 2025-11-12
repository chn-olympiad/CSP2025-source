//ccf orz
#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f*=-1;
		c=getchar();
	}while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return f*x;
} 
const int M=1e6+10;
int n,m,k,ans=LLONG_MAX;
int a[M][3],b[19][M];
bool c[19];
struct edge{
	int w,to;
};
vector<edge> e[M];
inline void f(int dep){
	if(dep!=k){
		c[dep]=1;
		f(dep+1);
		c[dep]=0;
		f(dep+1);
		return;
	}
	for(int i=1;i<=m;i++) e[i].clear();
	int res=0,x=1;
	for(int i=1;i<=k;i++){
		if(c[i]==1){
			res+=b[i][1]+b[i][1+i];
		}
	}
	for(int i=1;i<=m;i++){
		int x1=a[i][0],x2=a[i][1];
		if(x1<=k&&c[i]==1){
			e[x1].push_back({b[i][1+x2],x2});
			e[x2].push_back({b[i][1+x1],x1});
		}
		e[x1].push_back({a[i][2],x2});
		e[x2].push_back({a[i][2],x1});
	}
	priority_queue<PII,vector<PII>,greater<PII> > q;
	bool vis[M]={0};
	q.push({0,1});
	vis[1]=1;
	while(!q.empty()){
		PII t=q.top();
		q.pop();
		int w=t.first,v=t.second;
		res+=w;
		for(edge x:e[v]){
			int w2=x.w,v2=x.to;
			if(!vis[v2]){
				q.push({w2,v2});
				vis[v2]=1;
			}
		}
	}
	ans=min(ans,res);
	return; 
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		a[i][0]=read();
		a[i][1]=read();
		if(a[i][0]>a[i][1]) swap(a[i][0],a[i][1]);
		a[i][2]=read();
	}
	for(int i=1;i<=k;i++){
		b[i][1]=read();
		for(int j=1;j<=n;j++) b[i][j+1]=read();
	}
	f(1);
	cout<<ans;
	return 0;
}
