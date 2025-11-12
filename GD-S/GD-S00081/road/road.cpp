#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb emplace_back
#define fr first
#define sc second
typedef const int Int;
typedef pair<int,int> pii;

inline  Int read(){
	int x=0;char c=getchar();bool f=(c=='-');
	while(!isdigit(c))c=getchar(),f|=(c=='-');
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}

Int N=1e4+5;

int n,m,k;

int u,v,w;

struct edge{
	int u,v,w;
	inline const bool operator <(const edge &a)const{
		return w<a.w;
	}
}E[1000005];

int c[15][N];

edge st[N];
int hs;

int fa[N+20];

inline int find(Int &x){
	return x==fa[x]?x:find(fa[x]);
}

inline void uni(int x,int y){
	x=find(x),y=find(y);
	fa[y]=x;
}

LL ans;

inline void inibin(Int &siz){
	for(int i=1;i<=siz;i++)fa[i]=i;
}

LL rem;

bool B[N];

edge adt[N*10];
int h;

void dfs(Int &i=1){
	if(i>k){
//		cout<<"ok"<<endl;
		LL cnt=0;
		inibin(n+k);
		if(rem>ans)return;
		for(int i=1;i<=k;i++)if(B[i])for(int j=1;j<=n;j++)adt[++h]=edge{j,n+i,c[i][j]};
		sort(adt+1,adt+1+h);
//		cout<<"siz: "<<l1<<" "<<l2<<endl;
		int i=0,j=0;
		for(;i<=hs;i++){
			while(j<=h&&adt[j]<st[i]){
				if(find(adt[j].u)==find(adt[j].v)){
					j++;
					continue;
				}
				cnt+=adt[j].w;
				uni(adt[j].u,adt[j].v);
				j++;
			}
			if(find(st[i].u)==find(st[i].v))continue;
			cnt+=st[i].w;
			uni(st[i].u,st[i].v);
			if(cnt+rem>ans){
				h=0;
				return;
			} 
		}
		while(j<=h){
			if(find(adt[j].u)==find(adt[j].v)){
				j++;
				continue;
			}
			cnt+=adt[j].w;
			uni(adt[j].u,adt[j].v);
			if(cnt+rem>ans){
				h=0;
				return;
			}
			j++;
		}
		ans=min(ans,cnt+rem); 
		h=0;
		return;
	}
	dfs(i+1);
	B[i]=true;rem+=c[i][0];
	dfs(i+1);
	B[i]=false;rem-=c[i][0];
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	inibin(n);
	for(int i=1;i<=m;i++)E[i].u=read(),E[i].v=read(),E[i].w=read();
	for(int i=1;i<=k;i++){
		c[i][0]=read();
		for(int j=1;j<=n;j++)c[i][j]=read();
	}
	sort(E+1,E+1+m);
	for(int i=1;i<=m;i++){
		if(find(E[i].u)==find(E[i].v))continue;
		ans+=E[i].w;
		uni(E[i].u,E[i].v);
		st[++hs]=E[i];
	}
	dfs();
	printf("%lld",ans);
	return 0;
}



































