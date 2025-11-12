#include<bits/stdc++.h>
using namespace std;
#define int long long
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=12140,M=1000060;
int n,fa[N],m,k,ans,cnt;
struct node{
	int u,v,w;
	bool operator<(const node hh)const{
		return w<hh.w;	
	}
}a[M],b[M],d[15][N],now[M],kk[M];
int c[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	qwq;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(find(u)!=find(v)){
			b[++cnt]=a[i];
			ans+=w;
			merge(u,v);
		}
		if(cnt==n-1) break;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			d[i][j]={i+n,j,w};
		}
		sort(d[i]+1,d[i]+1+n);
	}
	for(int i=1;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++) fa[j]=j;
		int res=0;
		int tot=0;
		int ti=0;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				ti++;
				res+=c[j+1];
				if(res>=ans) break;
				if(tot==0){
					for(int p=1;p<=n;p++){
						now[++tot]=d[j+1][p];
					}
				}
				else{
					int ls1=1,ls2=1;
					now[tot+1].w=1e18;
					d[j+1][n+1].w=1e18;
					for(int p=1;p<=n+tot;p++){
						if(now[ls1].w<=d[j+1][ls2].w){
							kk[p]=now[ls1];
							ls1++;
						}
						else{
							kk[p]=d[j+1][ls2];
							ls2++;
						}
					}
					now[tot+1].w=0;
					d[j+1][n+1].w=0;
					for(int p=1;p<=n+tot;p++){
						now[p]=kk[p];
					}
					tot+=n;
				}
			}
		}
		int ls1=1,ls2=1;
		for(int j=1;j<=n+ti-1;j++){
			if(res>=ans) break;
			if(ls1<=cnt&&ls2<=tot&&b[ls1].w<=now[ls2].w){
				int u=b[ls1].u,v=b[ls1].v,w=b[ls1].w;
				if(find(u)!=find(v)){
					res+=w;
					merge(u,v);
				}
				else j--;
				ls1++;
				continue;
			}
			if(ls1<=cnt&&ls2<=tot&&b[ls1].w>now[ls2].w){
				int u=now[ls2].u,v=now[ls2].v,w=now[ls2].w;
				if(find(u)!=find(v)){
					res+=w;
					merge(u,v);
				}
				else j--;
				ls2++;
				continue;
			}
			if(ls1<=cnt){
				int u=b[ls1].u,v=b[ls1].v,w=b[ls1].w;
				if(find(u)!=find(v)){
					res+=w;
					merge(u,v);
				}
				else j--;
				ls1++;
				continue;
			}
			if(ls2<=tot){
				int u=now[ls2].u,v=now[ls2].v,w=now[ls2].w;
				if(find(u)!=find(v)){
					res+=w;
					merge(u,v);
				}
				else j--;
				ls2++;
				continue;
			}
		}
		ans=min(ans,res);
//		cout<<"i="<<i<<" res="<<res<<" ans="<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
