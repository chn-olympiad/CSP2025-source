#include<bits/stdc++.h>
using namespace std;
const int N=1e6+86;
struct node{
	int u,v,w;
}e[N];
bool cmp(node a,node b){
	if(a.w==b.w) return a.u<b.u;
	else return a.w<b.w;
}
int f[N];
int fd(int x){
	if(f[x]==x) return x;
	else return f[x]=fd(f[x]);
}
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+(int)ch-'0'; ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k; cin>>n>>m>>k;
	if(k==0){
		long long ans=0;
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
		for(int i=1;i<=m;++i){
			int u,v,w; //scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			e[i].u=read(); e[i].v=read(); e[i].w=read();
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;++i){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(fd(u)!=fd(v)){
				f[fd(v)]=fd(u);
				ans+=w;
			}
		}
		cout<<ans;
	}else{
		cout<<0;	
	}
	
	return 0;
}
