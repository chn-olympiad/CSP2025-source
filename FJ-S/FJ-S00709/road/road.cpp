#include <cstdio>
#define MAXN 100005
#define MAXM 1000000
#define MAXK 12
using namespace std;

int n,m,k,u[MAXM],v[MAXM],w[MAXM],c[MAXK],a[MAXK][MAXN],ans=0x3f3f3f3f;
bool repair[MAXK],viscity[MAXN];

inline int min(int a,int b){return a<b?a:b;}
int read(){
	int rx=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		rx=rx*10+ch-'0';
		ch=getchar();
	}
	
	return rx;
}
void write(int x){
	static int sta[52];
	int top=0;
	do{
		sta[top++]=x%10;
		x/=10;
	}while(x);
	while(top)putchar(sta[--top]+'0');
}

void dfs(int now, int cost, int cnt){
	if(cnt>n){
		ans=min(ans,cost);
		return;
	}
	for(int i=0;i<m;++i){
		if(u[i]==now){
			if(viscity[v[i]])continue;
			viscity[v[i]]=true;
			dfs(v[i],cost+w[i],cnt+1);
			viscity[v[i]]=false;
		}else if(v[i]==now){
			if(viscity[u[i]])continue;
			viscity[u[i]]=true;
			dfs(u[i],cost+w[i],cnt+1);
			viscity[u[i]]=false;
		}
	}
	// through village
	for(int i=0;i<k;++i){
		if(!repair[i]){
			repair[i]=true;
			cost+=c[i];
		}
		for(int j=1;i<=n;++j){
			if(viscity[j])continue;
			viscity[j]=true;
			dfs(j,cost+a[k][j],cnt+1);
			viscity[j]=false;
			repair[i]=false;
		}
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read();m=read();k=read();
	for(int i=0;i<m;++i){
		u[i]=read();
		v[i]=read();
		w[i]=read();
	}
	// special A solve
	for(int i=0;i<k;++i){
		c[i]=read();
		for(int j=0;j<n;++j){
			a[i][j]=read();
		}
	}
	
	viscity[0]=true;
	dfs(1,0,1);
	
	write(ans);
	
	return 0;
}
