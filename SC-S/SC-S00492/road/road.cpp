#include<bits/stdc++.h>
using namespace std;
const int N=1100007;
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void mer_(int x,int y){
	x=find(x),y=find(y);
	fa[y]=x;
}
bool que_(int x,int y){
	return find(x)==find(y);
}
struct way{
	int u,v,l;
}ways[N];
bool cmp(way x,way y){
	return x.l<y.l;
}
int c[17];
void fread(int &a){
	a=0;
	static char ch;
	while(ch<48||ch>57) ch=getchar();
	while(ch>=48&&ch<=57){
		a*=10;
		a+=(ch^48);
		ch=getchar();
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		fread(ways[i].u);
		fread(ways[i].v);
		fread(ways[i].l);
	}
	int w=m;
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++){
			w++;
			int x;
			fread(x);
			ways[w].u=n+i,ways[w].v=j,ways[w].l=x;
		}
	}
	sort(ways+1,ways+w+1,cmp);
	long long nn_ans=0x0f0f0f0f0f0f0f0f;
	for(int s=0;s<(1<<k);s++){
		for(int i=1;i<=n+k;i++) fa[i]=i;
		long long ans=0;
		int tt=n;
		for(int xx=1,i=1;i<=k;xx<<=1,i++){
			if(xx&s) ans+=c[i],tt++;
		}
		for(int i=1;i<=w;i++){
			if(tt==1) break;
			int u=ways[i].u,v=ways[i].v,l=ways[i].l;
			if(u<=n&&!que_(u,v)){
				mer_(u,v);
				ans+=l;
				tt--;
			}
			if(u>n&&(s&1<<(u-n-1))&&!que_(u,v)){
				mer_(u,v); 
				ans+=l;
				tt--;
			}
		}
		nn_ans=min(nn_ans,ans);
	}
	printf("%lld",nn_ans);
	return 0;
}