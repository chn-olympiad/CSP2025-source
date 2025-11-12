#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+5;
int c[15],d[15][N];
const int M=1e6+5;
struct code{
	int u,v,w;
}a[M],b[M];
int f[N];
int findd(int x){
	if(f[x]==x)return x;
	return f[x]=findd(f[x]);
}
bool cmp(code x,code y){
	return x.w<y.w;
}
void sol(){
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;++i)f[i]=i;
	long long ans=0;int tot=n;
	for(int i=1;i<=m;++i){
		int x=findd(a[i].u),y=findd(a[i].v);
		if(x!=y){
			f[x]=y;
			--tot;
			ans+=a[i].w;
			if(tot==1)break;
		}
	}
	cout<<ans;
}
int pos[15],dis[1005][1005];
long long ans=LONG_LONG_MAX;
void dfs(int p){
	if(p>k){
		int cnt=0;long long sum=0;
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				dis[i][j]=-1;
			}
		}
		for(int i=1;i<=m;++i){
			if(dis[a[i].u][a[i].v]!=-1)
				dis[a[i].u][a[i].v]=min(dis[a[i].u][a[i].v],a[i].w);
			else dis[a[i].u][a[i].v]=a[i].w;
		}
	//	for(int i=1;i<=m;++i)b[i]=a[i];
		for(int i=1;i<=k;++i){
			if(pos[i]){
				sum+=c[i];
				if(sum>=ans)return; 
				for(int l=1;l<n;++l){
					for(int r=l+1;r<=n;++r){
						if(dis[l][r]!=-1)
							dis[l][r]=min(dis[l][r],d[i][l]+d[i][r]);
						else dis[l][r]=d[i][l]+d[i][r];
					//	b[++cnt].u=l,b[cnt].v=r,b[cnt].w=d[i][l]+d[i][r];
					}
				}
			}
		}
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				if(dis[i][j]!=-1){
					b[++cnt]={i,j,dis[i][j]};
				}
			}
		}
		sort(b+1,b+cnt+1,cmp);
		for(int i=1;i<=n;++i)f[i]=i;
		int tot=n;
		for(int i=1;i<=cnt;++i){
			int x=findd(b[i].u),y=findd(b[i].v);
			if(x!=y){
				f[x]=y;
				--tot;
				sum+=b[i].w;
				if(sum>=ans)return; 
				if(tot==1)break;
			}
		}
		ans=min(ans,sum);
		return;
	}
	pos[p]=0;
	dfs(p+1);
	pos[p]=1;
	dfs(p+1);
}
void sol1(){
	int cnt=0;long long sum=0;
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			dis[i][j]=-1;
		}
	}
	for(int i=1;i<=m;++i){
		if(dis[a[i].u][a[i].v]!=-1)
			dis[a[i].u][a[i].v]=min(dis[a[i].u][a[i].v],a[i].w);
		else dis[a[i].u][a[i].v]=a[i].w;
	}
	//	for(int i=1;i<=m;++i)b[i]=a[i];
	for(int i=1;i<=k;++i){
		for(int l=1;l<n;++l){
			for(int r=l+1;r<=n;++r){
				if(dis[l][r]!=-1)
					dis[l][r]=min(dis[l][r],d[i][l]+d[i][r]);
				else dis[l][r]=d[i][l]+d[i][r];
				//	b[++cnt].u=l,b[cnt].v=r,b[cnt].w=d[i][l]+d[i][r];
			}
		}
	}
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			if(dis[i][j]!=-1){
				b[++cnt]={i,j,dis[i][j]};
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=n;++i)f[i]=i;
	int tot=n;
	for(int i=1;i<=cnt;++i){
		int x=findd(b[i].u),y=findd(b[i].v);
		if(x!=y){
			f[x]=y;
			--tot;
			sum+=b[i].w;
			if(tot==1)break;
		}
	}
	cout<<sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	bool flag=1;
	for(int i=1;i<=k;++i){
		cin>>c[i];if(c[i]!=0)flag=0;
		for(int j=1;j<=n;++j){
			cin>>d[i][j];
		}
	}
	if(k==0){//1~4
		sol();//16pts
		return 0;
	}
	for(int i=1;i<=m;++i){
		if(a[i].u>a[i].v)swap(a[i].u,a[i].v);
	//	dis[a[i].u][a[i].v]=a[i].w;
	}
	if(flag){//A
		sol1();
		return 0;
	}
	dfs(1);
	cout<<ans;
	//希望能过1~12:48pts 
	//瓶颈在于2^k的抉择 
	return 0;
} 
