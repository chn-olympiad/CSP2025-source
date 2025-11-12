#include<cstdio>
#include<algorithm>

#define LL long long
#define gc() getchar()

using namespace std;

char ch;
void read(int &x){
	for(ch=gc();ch<'0'||ch>'9';ch=gc());
	for(x=0;ch>='0'&&ch<='9';ch=gc())x=x*10+(int)(ch-'0');
	return;
}

const int N=1e4+5,M=1e6+5,K=10;

int n,m,k,tmp;
struct edge{
	int ui,vi,wi;
}b[M],a[K][N];
int c[K];
bool cmp1(edge x,edge y){
	return x.wi<y.wi;
}

LL Ans,sm;

int fa[N];
int father(int x){return fa[x]==x?x:fa[x]=father(fa[x]);}
void link(int x,int y){fa[father(x)]=father(y);return;}

int d1,sz;
edge d[N*2],now[N];

bool bz[K];
void dfs(int x){
	if(x==k){
		sm=0;
		for(int id=0;id<k;id++){
			if(!bz[id])continue;
			sm+=c[id];
		}
		if(sm>=Ans)return;
		sz=n-1;
		for(int i=1;i<n;i++)now[i]=b[i];
		for(int id=0;id<k;id++){
			if(!bz[id])continue;
			d1=0;tmp=1;
			for(int i=1;i<=sz;i++){
				while(tmp<=n&&a[id][tmp].wi<now[i].wi){
					d[++d1]=a[id][tmp];
					tmp++;
				}
				d[++d1]=now[i];
			}
			for(int i=1;i<=n+k;i++)fa[i]=i;
			sz=0;
			for(int i=1;i<=d1;i++){
				if(father(d[i].ui)==father(d[i].vi))continue;
				link(d[i].ui,d[i].vi);
				now[++sz]=d[i];
			}
		}
		for(int i=1;i<=sz;i++)sm+=now[i].wi;
		Ans=min(Ans,sm);
		return;
	}
	bz[x]=1;
	dfs(x+1);
	bz[x]=0;
	dfs(x+1);
	return;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++){
		read(b[i].ui);
		read(b[i].vi);
		read(b[i].wi);
	}
	sort(b+1,b+m+1,cmp1);
	for(int i=0;i<k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			read(a[i][j].wi);
			a[i][j].ui=i+n+1;a[i][j].vi=j;
		}
		sort(a[i]+1,a[i]+n+1,cmp1);
	}
	
	for(int i=1;i<=n;i++)fa[i]=i;
	tmp=m;m=0;
	for(int i=1;i<=tmp;i++){
		if(father(b[i].ui)==father(b[i].vi))continue;
		link(b[i].ui,b[i].vi);
		b[++m]=b[i];Ans+=b[i].wi;
	}
	
	dfs(0);
	
	printf("%lld\n",Ans);
	
	return 0;
}
