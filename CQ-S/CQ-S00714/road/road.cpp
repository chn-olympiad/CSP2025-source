#include<bits/stdc++.h>
//#define int long long
using namespace std;
bool f1;
int n,m,x,y,z,k,fa[10001],c[11][10001],mp[1001][1001],d[11];
long long ans=LLONG_MAX,dis[1<<10];
bool f2;
struct dcz{
	int x,y,z,vis;
}a[2000001],e[2000001];
bool cmp(dcz x,dcz y){
	return x.z<y.z;
}
vector<int> v;
int gf(int x){
	if(fa[x]==x) return x;
	return fa[x]=gf(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	cout<<(&f1-&f2)/1024.0/1024.0<<"\n";
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		int x=min(a[i].x,a[i].y),y=max(a[i].x,a[i].y);
		a[i].x=x,a[i].y=y;
	}
	if(k==0){
		sort(a+1,a+m+1,cmp);
		int ans=0;
		for(int i=1;i<=m;i++){
			int x=a[i].x,y=a[i].y;
			int fx=gf(x),fy=gf(y);
			if(fx!=fy) fa[fy]=fx,ans+=a[i].z;
		}
		cout<<ans<<"\n";return 0;	
	}
	bool ff=1;
	for(int i=1;i<=k;i++){
		cin>>d[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
		ff&=(d[i]==0);
	}
	if(n<=1000&&k<=5){
		for(int i=0;i<(1<<k);i++){
			long long val=0;
			for(int j=1;j<=k;j++){
				if(i>>(j-1)&1) val+=d[j]; 
			}
//			cout<<i<<' '<<val<<"\n";
			for(int u=1;u<=n;u++){
				for(int v=u+1;v<=n;v++){
					mp[u][v]=0x3f3f3f3f;
				}
			}
			for(int j=1;j<=m;j++){
				mp[a[j].x][a[j].y]=min(mp[a[j].x][a[j].y],a[j].z);
			}
			for(int u=1;u<=n;u++){
				for(int v=u+1;v<=n;v++){
					for(int l=1;l<=k;l++){
						if(!(i>>(l-1)&1)) continue; 
						mp[u][v]=min(mp[u][v],c[l][u]+c[l][v]);
					}
				}
			}
			int tot=0;
			for(int u=1;u<=n;u++){
				for(int v=u+1;v<=n;v++){
//					cout<<mp[u][v]<<' ';
					e[++tot]={u,v,mp[u][v],0};
				}
//				cout<<'\n';
			}
			sort(e+1,e+tot+1,cmp);
			for(int j=1;j<=n;j++) fa[j]=j;
			for(int j=1;j<=tot;j++){
				int fx=gf(e[j].x),fy=gf(e[j].y);
				if(fx!=fy){
					fa[fy]=fx;
					val+=e[j].z;
				}
			}
//			cout<<val<<"\n";
			ans=min(ans,val);
		}
		cout<<ans<<"\n";
		return 0;
	}
//	cout<<ff<<"\n";
	if(ff){
		long long val=0;
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				mp[u][v]=0x3f3f3f3f;
			}
		}
		for(int j=1;j<=m;j++){
			mp[a[j].x][a[j].y]=min(mp[a[j].x][a[j].y],a[j].z);
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				for(int l=1;l<=k;l++){
					mp[u][v]=min(mp[u][v],c[l][u]+c[l][v]);
				}
			}
		}
		int tot=0;
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
//				cout<<mp[u][v]<<' ';
				e[++tot]={u,v,mp[u][v],0};
			}
//			cout<<'\n';
		}
		sort(e+1,e+tot+1,cmp);
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int j=1;j<=tot;j++){
			int fx=gf(e[j].x),fy=gf(e[j].y);
			if(fx!=fy){
				fa[fy]=fx;
				val+=e[j].z;
			}
		}
//		cout<<val<<"\n";
		ans=min(ans,val);
		cout<<ans;
	}
	return 0;
}
/*
20min t1 自己笑不笑。

题读错了，搞笑了。 

注意到这个 k 只有 10。

从 a->b 有两种走法，一种是 a->b 直接走或者是 a->x->b 这样去走。 

我们可以直接钦定哪些点要选。

直接暴力建边是 kn^2 的，这不可接受。

我可以去掉一些较大的边，但是枚举起点和终点还是 n^2 的。
 
红温了。 
*/
