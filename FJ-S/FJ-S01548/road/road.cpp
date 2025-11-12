#include<bits/stdc++.h>
using namespace std;
const int N=10015,M=2000005;
inline int read(){
	int x=0;
	char c;
	while(c=getchar())if(c>='0'&&c<='9')break;
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
int n,m,k,fa[N],s[1<<10][N],a[10][N],p[N<<1];
struct node{
	int x,y,z;
	inline friend bool operator < (node x,node y){
		return x.z<y.z;
	}
}e[M];
inline int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
inline bool cmp(int x,int y){
	return e[x].z<e[y].z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i)e[i].x=read(),e[i].y=read(),e[i].z=read();
	sort(e+1,e+m+1);
	for(int i=1;i<=n;++i)fa[i]=i;
	int now=0;
	long long minn=0;
	for(int i=1;i<=m;++i){
		int x=find(e[i].x),y=find(e[i].y);
		if(x!=y){
			fa[x]=y;
			s[0][++now]=i;
			minn+=e[i].z;
		}
	}
	for(int i=0;i<k;++i){
		for(int j=0;j<=n;++j)a[i][j]=read();
		for(int j=1;j<=n;++j){
			int id=m+i*n+j;
			e[id].x=n+1+i,e[id].y=j,e[id].z=a[i][j];
		}
	}
	for(int S=1;S<(1<<k);++S){
		int t=S,qq;
		for(int i=0;i<k;++i)if((S>>i)&1){
			t^=(1<<i);
			qq=i;
			break;
		}
		int num=n+__builtin_popcount(t)-1;
		for(int i=1;i<=num;++i)p[i]=s[t][i];
		for(int i=1;i<=n;++i)p[++num]=m+qq*n+i;
		sort(p+1,p+num+1,cmp);
		for(int i=1;i<=n+k;++i)fa[i]=i;
		now=0;
		long long sum=0;
		for(int i=0;i<k;++i)if((S>>i)&1)sum+=a[i][0];
		for(int ii=1;ii<=num;++ii){
			int i=p[ii];
			int x=find(e[i].x),y=find(e[i].y);
			if(x!=y){
				fa[x]=y;
				s[S][++now]=i;
				sum+=e[i].z;
			}
		}
		minn=min(minn,sum); 
	}
	cout<<minn;
}
