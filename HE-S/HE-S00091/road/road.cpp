#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v;
	long long w;
}a[200005];
int n,m,k;
long long ans,c[10005];
int fa[10005];
int fin(int x){
	if(fa[x]!=x)fa[x]=fin(fa[x]);
	return fa[x];
}
bool xg(int x,int y){
	int p=fin(x);
	int q=fin(y);
	if(p==q)return 0;
	fa[p]=q;
	return 1;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++)
			if(xg(a[i].u,a[i].v))
				ans+=a[i].w;
		cout<<ans;
	}else cout<<0;
	return 0;
}
/*
4 4 0
1 3 4
1 4 3
2 3 1
2 4 2

*/
