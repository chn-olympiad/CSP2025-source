#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,k;
long long ans=LONG_MAX;
struct ROAD{
	int u,v,w;
}a[N];
struct TWON{
	int v,ci[N];
}t[15];
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return find(fa[x]);
}
//	int ge[1001],tiao[1001];
void dfs(int l,long long cnt,int sum){
	if(l==k+m+1)return;
	if(cnt>=ans)return ;
	if(sum==n-1){
		int q=find(1);
		for(int i=2;i<=n;i++){
			if(find(i)!=q){
				return;
			}
		}
//			for(int i=0;i<sum;i++){
//				ge[i]=tiao[i];
//			}
		ans=cnt;
	}
	if(l<m)for(int i=l+1;i<=n;i++){
		int x=a[i].u,y=a[i].v,z=a[i].w;
		int xx=find(x),yy=find(y);
		if(xx==yy)continue;
		fa[yy]=xx;
//			tiao[sum]=i;
		dfs(i,cnt+a[i].w,sum+1);
		fa[yy]=yy;
	}
	if(l>=m)for(int i=l-m+1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int xx=find(j);
			for(int u=j+1;u<=n+1;u++){
				int yy=find(u);
				if(xx==yy)continue;
				fa[yy]=xx;
//					tiao[sum]=i+m;
				dfs(i+m,cnt+t[i].v+t[i].ci[j]+t[i].ci[u],sum+1);
				fa[yy]=yy;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		bool f=1;
	 	cin>>t[i].v;
	 	if(t[i].v)f=0;
		for(int j=1;j<=n;j++){
			cin>>t[i].ci[j];
			if(t[i].ci[j])f=0;
		} 
		if(f){
			cout<<0;
			return 0;
		}
	} 
	dfs(0,0,0);
//	for(int i=0;i<n-1;i++){
//		cout<<ge[i]<<' ';
//	}
//	cout<<endl;
	cout<<ans;
	return 0;
}
