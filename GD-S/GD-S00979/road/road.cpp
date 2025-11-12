#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
const int NN = 2e3+10;
const int M = 10+10;
long long n,m,k,u[N],v[N],w[N],c[M],a[M][N],d[NN][NN];
long long fa[N];
int find(int x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
void merge(int x,int y){
	if(x<y)swap(x,y);
	fa[find(x)]=find(y);
}
struct node{
	long long u,v,w;
}r[N],r2[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
long long ku(){
	sort(r+1,r+m+1,cmp);long long ans=0;
	for(int i = 1; i <= m; i++){
		if(find(r[i].u)==find(r[i].v))continue;
		merge(r[i].u,r[i].v);
		ans+=r[i].w;
	}
	return ans;
}
long long ku2(long long cnt){
	sort(r2+1,r2+cnt+1,cmp);long long ans=0;
	for(int i = 1; i <= cnt; i++){
		if(find(r2[i].u)==find(r2[i].v))continue;
		merge(r2[i].u,r2[i].v);
		ans+=r2[i].w;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i]; 
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	if(k==0){
		for(int i = 1; i <= m; i++){
			r[i].u=u[i];r[i].v=v[i];
			r[i].w=w[i];
		}
		for(int i = 1; i <= n; i++){
			fa[i]=i;
		}
		cout << ku();return 0;
	}
	if(k<=5){
		long long ans=1e18;
		for(int es = 0; es < (1<<k); es++){
			long long anss=0,cnt=0;
			for(int i = 1; i <= n+k; i++){
				for(int j = 1; j <=n+k; j++){
					d[i][j]=2e9;
				}
			}
			for(int i = 1; i <=m; i++){
				d[u[i]][v[i]]=w[i];
				d[v[i]][u[i]]=w[i];
			}
			for(int i = 1; i <= n; i++){
				for(int l = 1; l <= k; l++){
					if((es>>(l-1))&1){
						d[i][n+l]=a[l][i];
					}
				}
			}
			for(int l = 1; l <= k; l++){
				if((es>>(l-1))&1){
					anss+=c[l];
				}
			}
			for(int i = 1; i <= n+k; i ++){
				for(int j = i+1; j <= n+k; j++){
					if(d[i][j]!=2e9){
						r2[++cnt].u=i;
						r2[cnt].v=j;
						r2[cnt].w=d[i][j];
					}
				}
			}
			for(int i = 1; i <= n+k; i++){
				fa[i]=i;
			}
			long long kk=ku2(cnt);
			ans=min(ans,anss+kk);
		}
		cout << ans;return 0;
	}
	return 0;
}

