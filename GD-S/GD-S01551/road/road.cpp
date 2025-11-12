#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
	bool operator <(const node &q) const{
		return w<q.w;
	}
} a[1000009],sc[150009],cs[150009];
int anc[10039],tp=0,c[19],aa[19][10039],tp2;
int f(int u){
	if(u!=anc[u])anc[u]=f(anc[u]);
	return anc[u];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,fu,fv,ans=1e18,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)anc[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		fu=f(a[i].u);
		fv=f(a[i].v);
		if(fu!=fv){
			anc[fu]=fv;
			tp++;
			cs[tp]=a[i];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>aa[i][j];
		}
	}
	tp2=tp;
	for(int i=1;i<=tp2;i++)sc[i]=cs[i];
	for(int i=0;i<(1<<k);i++){
		sum=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1){
				sum+=c[j];
				for(int l=1;l<=n;l++){
					tp++;
					cs[tp]={l,n+j,aa[j][l]};
				}
			}
		}
		for(int i=1;i<=n+k;i++)anc[i]=i;
		sort(cs+1,cs+tp+1);
		for(int i=1;i<=tp;i++){
			fu=f(cs[i].u);
			fv=f(cs[i].v);
			if(fu!=fv){
				anc[fu]=fv;
				sum+=cs[i].w;
			}
		}
		tp=tp2;for(int i=1;i<=tp2;i++)cs[i]=sc[i];
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
