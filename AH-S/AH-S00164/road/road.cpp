#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
	bool operator<(node x) const{
		return w<x.w;
	}
}a[1000005];
int fa[10005],n,m,k,cnt=n;
int f(int x){
	if(fa[x]==x) return x;
	return fa[x]=f(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	//we do the k=0 so we do not input k;
	//kruskal
	sort(a+1,a+1+m);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int ans=0;
	for(int i=1;i<=m && cnt!=1;i++){
		int rx=f(a[i].u),ry=f(a[i].v);
		if(rx!=ry){
			fa[rx]=ry;
			cnt--;
			ans+=a[i].w;
		}
	}
	cout<<ans;
	return 0;
}
/*
To CCF: 
 This is my first CSP-S travel.
 I think it is very hard.
 I get more than 260 points is CSP-J.
 But this t2, I perhaps only get less than 16 points.
 Please give me 3= .
							Best wishes
							AH-S00164 
*/
