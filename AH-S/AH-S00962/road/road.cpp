#include<bits/stdc++.h>
using namespace std;
const int MAXN=20005;
const int MAXM=2000005;

int n,m,k;
int kk[15];
int f[MAXN];
int a[15][MAXN];
long long answer=1e18;

struct pxy{
	int u,v,w;
}e[MAXM];

inline bool cmp(pxy x, pxy y){
	if(x.w!=y.w) return x.w<y.w;
	return x.u<y.u;
}

inline int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

inline void answer1(){
	for(int i=1; i<=n; i++) f[i]=i;
	sort(e+1,e+m+1,cmp);
	
	int cnt=0;
	long long ans=0;
	for(int i=1; i<=m; i++){
		int x=e[i].u,y=e[i].v;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			f[fx]=fy;
			cnt++;
			ans=ans+1ll*e[i].w;
		}
		if(cnt==n-1) break;
	}
	printf("%Illd\n" ,ans);
}

inline void answer2(){
	int nn=n,mm=m; n+=k;
	for(int i=1; i<=k; i++){
		for(int j=1; j<=nn; j++) e[++mm]={nn+i,j,a[i][j]};
	}
	for(int i=1; i<=n; i++) f[i]=i;
	sort(e+1,e+mm+1,cmp);
	
	int cnt=0;
	long long ans=0;
	for(int i=1; i<=mm; i++){
		int x=e[i].u,y=e[i].v;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			f[fx]=fy;
			cnt++;
			ans=ans+1ll*e[i].w;
		}
		if(cnt==n-1) break;
	}
	n-=k;
	printf("%Illd\n" ,ans);
}

inline void answer3(int x){
	long long ans1=0;
	int nn=n,mm=m; n+=x;
	for(int i=1; i<=x; i++){
		ans1+=1ll*a[kk[i]][0];
		for(int j=1; j<=nn; j++) e[++mm]={nn+i,j,a[kk[i]][j]};
	}
	if(ans1 >= answer) return ;
	for(int i=1; i<=n; i++) f[i]=i;
	for(int i=n+1; i<=n+k; i++) f[i]=0;
	sort(e+1,e+mm+1,cmp);
	
	int cnt=0;
	for(int i=1; i<=mm; i++){
		int x=e[i].u,y=e[i].v;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			f[fx]=fy;
			cnt++;
			ans1=ans1+1ll*e[i].w;
		}
		if(cnt==n-1) break;
	}
	n-=x;
	answer=min(answer,ans1);
	return ;
}

inline void dfs(int sk, int x){
	if(sk==k+1){
		answer3(x);
		return ;
	}
	dfs(sk+1,x);
	kk[x+1]=sk;
	dfs(sk+1,x+1);
	kk[x+1]=0;
}

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

int main(){
	freopen("road.in","r",stdin);		//zhuyi!!!!!
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d" ,&n,&m,&k);
	for(int i=1; i<=m; i++){
		//scanf("%d%d%d" ,&e[i].u,&e[i].v,&e[i].w);
		e[i].u=read();e[i].v=read();e[i].w=read();
	}
	int flag1=0,flag2=0;
	for(int i=1; i<=k; i++){
		for(int j=0; j<=n; j++){
			a[i][j]=read();
			if(j!=0 && a[i][j]==0) flag1=1;
		}
		if(a[i][0]!=0 || flag1==0) flag2=1;
		flag1=0;
	}
	sort(e+1,e+m+1,cmp);
	
	if(k==0){
		answer1();
	}
	if(flag2==0){
		answer2();
	}
	
	dfs(1,0);
	printf("%Illd\n" ,answer);
}//Ren5Jie4Di4Ling5%
