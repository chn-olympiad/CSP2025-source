#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
const int M=1e6+5;
int n,m,k,fa[N],t[11][N];
struct edge{
	int u,v,s;
	bool operator<(edge t)const{
		return s<t.s;
	}
}e[6*M];
int getf(int x){
	if(!fa[x]) return x;
	return fa[x]=getf(fa[x]);
}
int read(){
	int f=1,x=0;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(); 
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();
		e[i].v=read();
		e[i].s=read();
	}
	if(n*n*k<=1e7)
		for(int i=1;i<=k;i++)
			for(int j=0;j<=n;j++){
				t[i][j]=read();
				for(int l=1;l<j;l++)
					e[++m]={l,j,t[i][0]+t[i][j]+t[i][l]};
			}
	sort(e+1,e+m+1);
	memset(fa,0,sizeof(fa));
	int tot=0,cnt=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u;
		int v=e[i].v;
		if(getf(u)!=getf(v)){
			fa[getf(u)]=getf(v);
			tot+=e[i].s;
			cnt++;
			if(cnt==n-1) break;
		}
	}
	printf("%lld",tot);
	return 0;
}
