#include<iostream>
#include<algorithm>
using namespace std;
const int si=1e6+10,ad=1e7;
#define int long long
struct edge{
	int u,v,w;
}a[ad+si];
int n,m,k;
int fa[si];
int find(int a){
	if(a==fa[a])return a;
	return fa[a]=find(fa[a]);
}
void com(int q1,int q2){
	fa[find(q1)]=fa[find(q2)];
}
int c,v[si],ans=0;
bool cmp(edge q1,edge q2){
	return q1.w<q2.w;
}
int in(){
	int kkk=0;
	scanf("%lld",&kkk);
	return kkk;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in(),m=in(),k=in();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
		a[i].u=in(),a[i].v=in(),a[i].w=in();
	for(int i=1;i<=k;i++){
		c=in();
		int to=0;
		for(int j=1;j<=n;j++)
			v[j]=in(),v[j]==0?to=j:0;
		for(int j=1;j<=n;j++){
			if(j==to)continue;
			a[++m]={to,j,v[j]};
		}
	}sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		//printf("%d %d %d %d\n",u,v,w,ans);
		if(find(u)==find(v))continue;
		ans+=w;
		com(u,v);
	}printf("%lld",ans);
	return 0;
}
