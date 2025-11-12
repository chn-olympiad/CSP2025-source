#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int c[15],a[15][10005];
int ans,cnt;
bool f;
int ka[15],fa[10005];
struct node{
	int u,v,w;
}r[100005];
struct vil{
	int c,a[10005];
}v[15];
bool cmp(node x,node y){
	return x.w<y.w;
}
bool cmp2(vil a,vil b){
	return a.c<b.c;
}
int find(int x){
	if(fa[x]==x) return x;
	return find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>v[i].c;
		for(int j=1;j<=n;j++) cin>>v[i].a[j];
	}
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(r[i].u);
		int fy=find(r[i].v);
		if(fx!=fy){
			int cost=r[i].w,vi=0;
			for(int j=1;j<=k;j++){
				for(int l=1;l<=n;l++){
					if(find(l)==fx){
						for(int r=1;r<=n;r++){
							if(find(r)==fy){
								if(ka[j]){
									if(v[j].a[l]+v[j].a[r]<cost){
										ka[vi]--;
										vi=j;
										ka[vi]++;
										cost=v[j].a[l]+v[j].a[r];
									}
								}
								else{
									if(v[j].c+v[j].a[l]+v[j].a[r]<=cost){
										ka[vi]--;
										vi=j;
										ka[vi]++;
										cost=v[j].c+v[j].a[l]+v[j].a[r];
									}
								}
							}
						}
					}
				}
			}//k>0
			fa[fy]=fx;
			ans+=cost;
		}
		cnt++;
		if(cnt==n-1){
			f=1;
			break;
		}
	}
	if(f) cout<<ans;
	return 0;
}