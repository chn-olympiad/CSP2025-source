#include<bits/stdc++.h>
using namespace std;
int n,m,k,op;
long long minn=1e18;
int fa[200050];
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
struct gz{
	int v;
	int l[200050];
} kk[15];
struct lu{
	int u,v,w;
}a[2000005];
bool cmp(lu a,lu b){
	return a.w<b.w;
}
void js(int vis){
	int t=0,b=m;
	long long ans=0;
	while(vis){
		++t;
		if(vis%2==1){
			for(int i=1;i<=n;i++){
				++b;
				a[b].u=n+t;
				a[b].v=i;
				a[b].w=kk[t].l[i];
			}
			fa[n+t]=n+t;
			ans+=kk[t].v;
		}
		vis/=2;
	}
	sort(a+1,a+b+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=b;i++){
		int xx=find(a[i].v),yy=find(a[i].u);
		if(xx!=yy)fa[xx]=yy,ans+=a[i].w;
		if(ans>minn)return ;
	}
	minn=min(minn,ans);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie();
	cout.tie();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>kk[i].v;
		op+=kk[i].v;
		for(int j=1;j<=n;j++)cin>>kk[i].l[j];
	}
	if(op==0){
		int vis=pow(2,k)-1;
		js(vis);
	}else for(int i=0;i<pow(2,k);i++){
		js(i);
	}
	cout<<minn;
	return 0;
}
