#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+10,M=2e6+10;
int n,m,k,c[11],p1,fa[N],d[11][N],vis[11][N];
vector<int>e;
struct edge{
	int x,y,z;
	bool operator < (const edge &p) const{
		return z<p.z;
	}
}a[M];
int fd(int x){
	if (x==fa[x]) return x;
	return fa[x]=fd(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=k;i++){
		cin >> c[i];
		p1+=c[i];
		for (int j=1;j<=n;j++){
			int x;
			cin >> x;
			p1+=x;
			d[i][j]=x;
//			a[m+(i-1)*n+j]={n+i,j,x};
		}
	}
	if (k==0){
		sort(a+1,a+m+1);
		int res=0;
		for (int i=1;i<=m;i++){
			int xx=fd(a[i].x),yy=fd(a[i].y);
			if (xx!=yy){
				fa[xx]=yy;
				res+=a[i].z;
				e.push_back(i);
			}
		}
		cout << res;
		return 0;
	}
	if (p1==0){
		cout << 0;
		return 0;
	}
	sort(a+1,a+m+1);
	int res=0;
	for (int i=1;i<=m;i++){
		int xx=fd(a[i].x),yy=fd(a[i].y);
		if (xx!=yy){
			fa[xx]=yy;
			res+=a[i].z;
			e.push_back(i);
		}
	}
	int ans=res,A=res;
//	for (int i:e){
//		for (int j=1;j<=k;j++){
//			int val=(!vis[j][a[i]])d[j][a[i].x]+d[j][a[i].y]+(!vis[j])*c[j];
//			if (a[i].z>=val){
//				ans=ans-a[i].z+val;
//				vis[j]=1;
//				break;
//			}
//		}
//		A=min(A,ans);
//	}
	cout << A;
//	for (int i=0;i<(1<<k);i++){
//		
//	}
}
