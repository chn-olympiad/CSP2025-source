#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e4+5;
const ll maxx=1e6+5;
struct node{
	ll l,r,v;
}ro[maxx*5];
bool cmp(node aa,node bb){
	return aa.v<bb.v;
}
ll n,m,k,cnt,ans,size;
ll c[15],a[maxn][15],fa[maxn];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	size=m;
	for(int i=1;i<=m;i++){
		cin>>ro[i].l>>ro[i].r>>ro[i].v;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[j][i];
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	if(k==0){
		sort(ro+1,ro+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(find(ro[i].l)!=find(ro[i].r)){
				cnt++;
				ans+=ro[i].v;
				fa[find(ro[i].l)]=find(ro[i].r);
			}
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=k;i++){
			for(int ii=1;ii<=n;ii++){
				for(int jj=1;jj<=n;jj++){
					if(ii!=jj) ro[++size].l=ii,ro[size].r=jj,ro[size].v=a[ii][i]+a[jj][i]+c[i];
				}
			}
		}
		sort(ro+1,ro+size+1,cmp);
		for(int i=1;i<=m;i++){
			if(find(ro[i].l)!=find(ro[i].r)){
				cnt++;
				ans+=ro[i].v;
				fa[find(ro[i].l)]=find(ro[i].r);
			}
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans;
	}
	
	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
