#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+50,M=1e7+50,inf=1e18;
struct p{
	int l,r,w;
}e[M];
bool cmp(p x,p y){
	return x.w<y.w;
}
int fa[M];
int cnt1[11];
int cnt2[11][M];
int find(int x){
//	cout<<x<<" "<<fa[x]<<endl;
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int n,m,k,idx,mx;
int kru(){
	int ans=0;
	sort(e+1,e+1+idx,cmp);
	for(int i=1;i<=mx;i++) fa[i]=i;
//	for(int i=1;i<=mx;i++) cout<<fa[i]<<endl;
	for(int i=1;i<=idx;i++){
		int fx=find(e[i].l),fy=find(e[i].r);
		if(fx==fy) continue;
		
		fa[fx]=fy;
		ans+=e[i].w;
	}
	return ans;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	int mx2=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].l>>e[i].r>>e[i].w;
	} 
	for(int i=0;i<k;i++){
		cin>>cnt1[i];
		mx2=max(mx2,cnt1[i]);
		for(int j=1;j<=n;j++){
			cin>>cnt2[i+1][j];
		}
	}
	int mn=inf;
	if(mx2==0){
		int anser=0;
		int i=(1<<k)-1;
		idx=m;
		anser=0;
		mx=n;
		for(int j=0;j<k;j++){
			if((i&(1<<j))==(1<<j)){
				for(int k=1;k<=n;k++){
					mx=max(mx,n+j+1);
					e[++idx].l=n+j+1;
					e[idx].r=k;
					e[idx].w=cnt2[j+1][k];
//					if(e[idx].w==0) cout<<e[idx].l<<" "<<e[idx].r<<endl;
				}
				anser+=cnt1[j];
			}
		}
		int o=kru();
//		cout<<n<<" "<<idx<<" "<<mx<<endl;
		mn=min(mn,anser+o);
	}
	else{
		int anser=0;
		for(int i=0;i<(1<<k);i++){
			idx=m;
			anser=0;
			mx=n;
			for(int j=0;j<k;j++){
				if((i&(1<<j))==(1<<j)){
					for(int k=1;k<=n;k++){
						mx=max(mx,n+j+1);
						e[++idx].l=n+j+1;
						e[idx].r=k;
						e[idx].w=cnt2[j+1][k];
					}
					anser+=cnt1[j];
				}
			}
			int o=kru();
		
			mn=min(mn,anser+o);
		}
	}

	cout<<mn<<endl;
}