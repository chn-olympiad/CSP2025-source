#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,a[15][10005],fx[10015],cnt[10015],ans=1e18;
struct node{
	int l,r,w;
}x[1100005],xx[100005];
bool cmp(node l,node r){
	return l.w<r.w;
}
int find(int x){
	return fx[x]==x?x:fx[x]=find(fx[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i].l>>x[i].r>>x[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(x+1,x+1+m,cmp);
	for(int i=1;i<=n;i++){
		fx[i]=i;
		cnt[i]=1;
	}
	int mx=0,add=0,nw_m=0;
//	cout<<1;
	for(int i=1;i<=m && (add<n-1 || x[i].w==mx);i++){
		int u=find(x[i].l),v=find(x[i].r);
		if(u!=v){
			add++;
			if(cnt[u]<cnt[v])swap(u,v);
			fx[v]=u;
			cnt[u]+=cnt[v];
			mx=x[i].w;
		}
		x[++nw_m]=x[i];
	}
	m=nw_m; 
	node cc;
	x[m+1]={0,0,(long long)(1e18)};
//	cout<<nw_m<<'\n';
	for(int kl=0;kl<(1<<k);kl++){
		nw_m=0;
		int sum=0,bian=n;
		for(int i=1;i<=k;i++){
			if(!(kl&(1<<(i-1)))){
				continue;
			}
			sum+=a[i][0];
			++bian;
			for(int j=1;j<=n;j++){
				xx[++nw_m]={bian,j,a[i][j]};
			}
		}
		sort(xx+1,xx+1+nw_m,cmp);
		for(int i=1;i<=bian;i++){
			fx[i]=i;
			cnt[i]=1;
		}
		xx[nw_m+1]={0,0,(long long)(1e18)};
		add=0;
		int l=1,r=1;
		for(int i=1;i<=nw_m+m && add<bian-1;i++){
			if(x[l].w<=xx[r].w){
				cc=x[l++];
			}
			else{
				cc=xx[r++];
			}
			if(sum>=ans)break;
			int u=find(cc.l),v=find(cc.r);
			if(u!=v){
				add++;
				if(cnt[u]<cnt[v])swap(u,v);
				fx[v]=u;
				cnt[u]+=cnt[v];
				sum+=cc.w;
			}
		}
		if(add!=bian-1)continue;
//		cout<<kl<<" "<<sum<<'\n'; 
		ans=min(ans,sum);
	}
	cout<<ans;
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

²»»áÑ½ 
80pts 
*/
