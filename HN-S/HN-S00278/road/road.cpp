#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int M=1e4+10;
int n,m,k;
int last[M];
struct sb{
	int to,pre,w;
}s[N*2];
int c[13];
vector <int> xl[M];
struct node{
	int u,v,w;
}a[N];
node t[N*2];
void gb(int l,int r){
	if(l==r) return ;
	int mid=(l+r)/2;
	gb(l,mid);
	gb(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(a[i].w<a[j].w) t[k++]=a[i++];
		else t[k++]=a[j++];
	}
	while(i<=mid) t[k++]=a[i++];
	while(j<=r) t[k++]=a[j++];
	for(int i=l;i<=r;i++) a[i]=t[i];
}
int cnt;
void add(int u,int v,int w){
	cnt++;
	s[cnt].to=v;
	s[cnt].pre=last[u];
	last[u]=cnt;
	s[cnt].w=w;
	return ;
}
int fa[M];
bool pd(int x,int y){
	if(x==y) return ;
	else return pd(fa[x],y);
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	//int u,v,w;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
		//add(u,v,w);
		//add(v,u,w);
	}
	
	for(int i=1;i<=k;i++){
		int a;
		scanf("%d",&c[i]); 
		
		for(int j=1;j<=n;j++){
			scanf("%d ",&b[j][0]);
			
		}
	}
	gb(1,m); 
	for(int i=1;i<=m;i++){
		if(fa[a[i].u]!=fa[a[i].v]){
			if(a[i].v<a[i].u) fa[a[i].v]=find(a[i].u);
			else if(a[i].v>a[i].u) fa[a[i].u]=find(a[i].v);
			ans+=a[i].w; 
		}
	}
	if(k!=0) ans=0;
	printf("%lld\n",ans);
	
	return 0;
}
