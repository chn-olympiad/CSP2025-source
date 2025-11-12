#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int nbs[20050],tot;
long long o[15];
long long minn,ans=LONG_LONG_MAX;
vector<int>vec[15];
int fa[20050],siz[20050];
int qread1(){
	int ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret;
}
long long qread2(){
	long long ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct edge{
	int x,y;
	long long v;
	bool flag=0;
}b[3000050];
bool cmp(edge x,edge y){
	return x.v<y.v;
}
void add(int x,int y,long long v,bool flag){
	tot++;
	b[tot].x=x;
	b[tot].y=y;
	b[tot].v=v;
	b[tot].flag=flag;
}
int init(int x,int op){
	int j=1,ret=0;
	while(x){
		if(x%2){
			for(auto i:vec[j]){
				b[i].flag=op;
			}
			ret++;
			minn+=o[j];
		}
		x/=2;
		j++;
	}
	return ret;
}
void prim(int l){
	int i=1;
	for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=1;
	for(int j=1;j<n+l;i++){
		if(b[i].flag&&find(b[i].x)!=find(b[i].y)){
			j++;
			minn+=b[i].v;
			if(minn>=ans)return;
			if(siz[find(b[i].x)]<siz[find(b[i].y)])siz[find(b[i].y)]+=siz[find(b[i].x)],fa[find(b[i].x)]=find(b[i].y);
			else siz[find(b[i].x)]+=siz[find(b[i].y)],fa[find(b[i].y)]=find(b[i].x);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v;long long w;
	for(int i=1;i<=m;++i){
		u=qread1();v=qread1();w=qread2();
		add(u,v,w,1);
		add(v,u,w,1);
	}
	bool flag=0;
	for(int i=1;i<=k;++i){
		o[i]=qread2();
		if(o[i])flag=1;
		for(int j=1;j<=n;j++){
			w=qread2();
			add(n+i,j,w,0);
			add(j,n+i,w,0);
		}
	}
	int M=pow(2,k)-1;
	sort(b+1,b+tot+1,cmp);
	for(int i=1;i<=tot;++i){
		if(b[i].x>n){
			vec[b[i].x-n].push_back(i);
			continue;
		}
		if(b[i].y>n){
			vec[b[i].y-n].push_back(i);
		}
	}
	for(int x,i=0;i<=M;++i){
		if(flag==0)i=M;
		minn=0;
		x=init(i,1);
		prim(x);
		ans=min(ans,minn);
		init(i,0);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
