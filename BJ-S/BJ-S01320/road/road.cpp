#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
const int M=6e6+10;
struct node{
	ll u,v,w;
}a[M];
ll n,m,k,c[N],cnt,d[N],fa[N],ans;
int cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	int flag=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=1;
		for(int j=1;j<=n;j++){
			scanf("%lld",&d[j]);
			if(d[j]!=0) flag=1;
		}
	}
	if(flag==0&&k!=0){
		cout<<0;
		return 0;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(a[i].u);
		int fy=find(a[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			cnt++;
			ans+=a[i].w;
			if(cnt==n-1) break;
		}
	}
	cout<<ans;
	return 0;
}
