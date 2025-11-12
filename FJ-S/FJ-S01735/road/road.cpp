#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}

const int N=2e4+10,M=2e6+10,inf=1e17+10;

int n,m,k;
int a[20][N],c[20];

struct edge{
	int from,to,w;
	friend bool operator<(const edge x,const edge y){
		return x.w<y.w;
	}
}e[M],E[M];

int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

int tot;
void pre_Mst(){
	sort(E+1,E+1+m);
	for(int i=0;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=E[i].from,y=E[i].to,z=E[i].w;
		int fx=find(x),fy=find(y);
		if(fx==fy)continue;
		e[++tot]=E[i];
		fa[fx]=fy;
	}
}

int tot_node;
int Mst(){
	int res=0;
	for(int i=1;i<=tot;i++)E[i]=e[i];
	sort(E+1,E+1+tot);
	for(int i=0;i<=n+k;i++)fa[i]=i;
	int tim=0;
	for(int i=1;i<=tot;i++){
		int x=E[i].from,y=E[i].to,z=E[i].w;
		int fx=find(x),fy=find(y);
		if(fx==fy)continue;
		fa[fx]=fy;
		res+=z;
		tim++;
		if(tim==tot_node-1)break;
	}
	return res;
}

signed main(){
	
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		E[i]=(edge){x,y,z};
	}
	pre_Mst();
	
	int flag=0;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0)flag=1;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	
	if(flag==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++tot]=(edge){n+i,j,a[i][j]};
			}
		}
		tot_node=inf;
		write(Mst());
		return 0;
	}
	
	int lst=tot;
	int res=inf;
	for(int S=0;S<=(1<<k)-1;S++){
		tot=lst;
		int tmp=0;
		tot_node=n;
		for(int i=1;i<=k;i++){
			if((S>>(i-1))&1){
				for(int j=1;j<=n;j++)e[++tot]=(edge){n+i,j,a[i][j]};
				tmp+=c[i];
				tot_node++;
			}
		}
		tmp+=Mst();
		res=min(res,tmp);
	}
	write(res);
	
	return 0;
}