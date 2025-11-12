#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N=2e6+114;
struct edge{
	int u,v,w;
	bool operator < (const edge &x) const{
		return w<x.w;
	}
}e[N];
int n,m,k;
int f[N];
int ad[15][100005];
int c[N]; 
int kc;
ll ans,ans2;
int findd(int x){
	if(x==f[x]) return x;
	return f[x]=findd(f[x]); 
}
void unionn(int x,int y){
	int a=findd(x),b=findd(y);
	if(a==b) return ;
	f[a]=b;
	return ;
}
inline int read(){
	int k=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) k=k*10+c-'0',c=getchar();
	return k*f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+m+1);
	kc=0;
	for(int i=1;i<=m;i++) {
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(findd(u)!=findd(v)) {
			ans+=w;
			unionn(u,v);
			++kc;
		}
		if(kc>n) break;
	}
	if(k==0) {
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n+50;i++) f[i]=i;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			ad[i][j]=read();
		}
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			e[++cnt].u=n+i;
			e[cnt].v=j;
			e[cnt].w=ad[i][j]+c[i];
		}
	}
	sort(e+1,e+m+k*n+1);
	kc=0;
	for(int i=1;i<=m+k*n;i++) {
		int u=e[i].u,v=e[i].v,w=e[i].w;
		//cout<<u<<" "<<v<<" "<<w<<endl;
		if(findd(u)!=findd(v)) {
			ans2+=w;
			unionn(u,v);
			++kc;
		}
		if(kc>n+k) break;
	}
	cout<<min(ans,ans2)<<endl;
	return 0;
} 








