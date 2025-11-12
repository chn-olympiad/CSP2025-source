#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
void read(int &n){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}n=x*f;
}
void read(ll &n){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}n=x*f;
}
const int N=1e4+15,M=1e6+15;
ll ans=1ll*1e9*1e5;
int n,m,k;
struct node{
	int u,v,w;
}g1[M],g2[M];
int c[15],a[15][N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
ll tmp,cnt;
il void check(node &edge){
//	cout<<"check"<<edge.u<<' '<<edge.v<<' '<<edge.w<<endl;
//	cout<<find(edge.u)<<' '<<find(edge.v)<<endl;
	if(find(edge.u)!=find(edge.v)){
		fa[find(edge.u)]=edge.v;
		tmp+=edge.w;cnt--;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++){
		read(g1[i].u);read(g1[i].v);read(g1[i].w);
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++)read(a[i][j]);
	}
	sort(g1+1,g1+1+m,cmp);
	for(int i=0;i<(1<<k);i++){
		int ad=0;
		tmp=0;cnt=n-1;
		int tot=0;
		for(int l=1;l<=k;l++){
			if(((i>>(l-1))&1)==0)continue;
			tmp+=c[l];cnt++;ad++;
			for(int j=1;j<=n;j++){
				tot++;g2[tot].u=l+n;g2[tot].v=j;g2[tot].w=a[l][j];
			}
		}
		sort(g2+1,g2+1+tot,cmp);
		for(int j=1;j<=n+k;j++)fa[j]=j;
		int l=1,L=1;
		while(l<=m&&L<=ad*n&&cnt){
			if(g1[l].w<g2[L].w){
				check(g1[l]);l++;
			}else{
				check(g2[L]);L++;
			}
		}
		while(l<=m&&cnt){
			check(g1[l]);l++;
		}
		while(L<=ad*n&&cnt){
			check(g2[L]);L++;
		}
//		cout<<tmp<<endl;
		ans=min(ans,tmp);
	}
	cout<<ans;
	return 0;
}

