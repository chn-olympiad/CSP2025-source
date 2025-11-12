#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int n,m,m1,k,u[1100000],v[1100000],w[1100000],c[20],a[20][11000];
long long ans=1000000000000000000;
int f[11000];
inline int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
struct node{
	int u,v,w;
}p;
vector<node>e[2000];
bool operator<(node x,node y){
	return x.w>y.w;
}
priority_queue<node>q;
inline void solve(int a){
	for(int i=1;i<=n+k;i++)f[i]=i;
	long long s=0;
	for(int i=1;i<=k;i++){
		if(a&(1<<(i-1)))s+=c[i];
	}
	//cout<<s<<endl;
	int x,y;
	while(!q.empty()){
		p=q.top();
		q.pop();
		x=find(p.u);
		y=find(p.v);
		if(x!=y){
			e[a].push_back(p);
			//cout<<p.u<<' '<<p.v<<' '<<p.w<<endl;
			f[x]=y;
			s+=p.w;
		}
	}
	ans=min(ans,s);
	//cout<<a<<' '<<s<<endl;
}
inline void read(int&s){
	char c=getchar();
	while(!('0'<=c&&c<='9'))c=getchar();
	s=0;
	while('0'<=c&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	//scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		read(u[i]);
		read(v[i]);
		read(w[i]);
	}//scanf("%d%d%d",&u[i],&v[i],&w[i]);
	for(int i=1;i<=k;i++){
		read(c[i]);
		//scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)read(a[i][j]);//scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=m;i++){
		q.push(node{u[i],v[i],w[i]});
	}
	solve(0);
	for(int i=1;i<(1<<k);i++){
		for(int j=k;j>=1;j--){
			if(i&(1<<(j-1))){
				int i1=i^(1<<(j-1));
				for(node l:e[i1])q.push(l);
				for(int l=1;l<=n;l++)q.push(node{n+j,l,a[j][l]});
				break;
			}
		}
		solve(i);
	}
	printf("%lld",ans);
	return 0;
}
