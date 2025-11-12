#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
	while(isdigit(ch)){res=(res<<1)+(res<<3)+ch-'0';ch=getchar();}
	return res*f;
}
void write(int x){
	if(x<0){putchar('-');write(-x);return;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,k,ans=2333331145141919810ll,f[23333],lar[23333];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
struct E{int u,v,w;};
struct node{int c,a[23333];}vi[13];
vector<E>edge;
bool cmp(E x,E y){return x.w<y.w;}
inline int kruskal(){
	vector<E>tmp=edge;
	int res=0;
	for(int i=1;i<=n+k;++i){f[i]=i;lar[i]=1;}
	sort(tmp.begin(),tmp.end(),cmp);
	for(int i=0;i<tmp.size();++i){
		int u=tmp[i].u,v=tmp[i].v,w=tmp[i].w;
		if(find(u)==find(v))continue;
		if(lar[find(u)]<lar[find(v)]){
			f[find(u)]=find(v);
			lar[find(v)]+=lar[find(u)];
		}else{
			f[find(v)]=find(u);
			lar[find(u)]+=lar[find(v)];
		}
		res+=w;
	}
	return res;
}
void dfs(int x,int now){
	if(x>k){
		ans=min(ans,now+kruskal());
		return;
	}
	for(int i=1;i<=n;++i){
		edge.push_back((E){n+x,i,vi[x].a[i]});
	}
	dfs(x+1,now+vi[x].c);
	for(int i=1;i<=n;++i)edge.pop_back();
	dfs(x+1,now);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;++i){
		int u,v,w;u=read();v=read();w=read();
		edge.push_back((E){u,v,w});
	}
	for(int i=1;i<=k;++i){
		vi[i].c=read();
		for(int j=1;j<=n;++j)vi[i].a[j]=read();
	}
	bool flag=1;
	for(int i=1;i<=k;++i){
		if(vi[i].c)flag=0;
	}
	if(!flag)dfs(1,0);
	else{
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j){
				edge.push_back((E){n+i,j,vi[i].a[j]});
			}
		}
		ans=kruskal();
	}
	write(ans);
	return 0;
}
//100+56~72+0~5+8~12=164~189
