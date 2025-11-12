#include<bits/stdc++.h>
#define ulp(i,a,b) for(int i=a;i<=b;i++)
#define dlp(i,a,b) for(int i=a;i>=b;i--)
#define inf 0x3f3f3f3f
#define int long long
#define il inline
#define push_back pb
#define pii pair<int,int>
#define hh putchar('\n')
#define kg putchar(' ')
#define fir first
#define sec second
#define lowbit ((i)&(-i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
il int read(){
	int num=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=1;
		c=getchar();
	}
	while(isdigit(c)){
		num=(num<<3)+(num<<1)+(c^48);
		c=getchar();
	}
	return f?-num:num;
}
il void write(int x){
	if(x<0)putchar('-'),x=-x;
	int stk[50],top=0;
	do{
		stk[++top]=x%10;
		x/=10;
	}while(x);
	dlp(i,top,1)putchar(stk[i]+'0');
}
#define M 1000005
#define N 10005
#define K 10
int n,m,k;
struct path{
	int u,v,w;
}P[M+N*(1<<K)];
int cnt=0;
int a[K+5][N];
int c[N];
int fa[N];
int hanser=0,tot=0;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool Union(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return false;
	fa[fx]=fy;
	return true;
}
signed main(){
	//k==0||c[j]==0&&E a[i][j]=0 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	ulp(i,1,m){
		int u=read(),v=read(),w=read();
		if(u!=v)P[++cnt]={u,v,w};
	}
	ulp(i,1,n)fa[i]=i;
	ulp(i,1,k){
		c[i]=read();
		int flag=0;
		ulp(j,1,n){
			a[i][j]=read();
			//write(a[i][j]),kg;
			if(a[i][j]==0)flag=j;//可以直接被视为该节点 
		}
		if(!flag)continue; 
		ulp(j,1,n){
			if(j!=flag){
				//write(a[i][j]);
				P[++cnt]={flag,j,a[i][j]};
			}
		}
	}
	
	sort(P+1,P+cnt+1,[&](path a,path b){
		return a.w<b.w;
	});
	ulp(i,1,cnt){
		int u=P[i].u,v=P[i].v,w=P[i].w;
		//write(w);
		if(Union(u,v)){
			hanser+=w,++tot;
		}
		if(tot==n-1){
			//ulp(i,1,n)write(find(i)),kg;
			return write(hanser),0;
		}
	}
	puts("No solution!");
	return 0;
} 
