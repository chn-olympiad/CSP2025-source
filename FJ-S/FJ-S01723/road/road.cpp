#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
const int K=12;
int n,m,k;
int c[K],d[K][N];
long long ans;
struct e
{
	int x,y,z;
};
e a[M];
long long hd[K][4];
inline bool cmp(e a,e b)
{
	return a.z<b.z;
}
int f[N];
inline int fa(int x)
{
	if(f[x]!=x){
		f[x]=fa(f[x]);
	}
	return f[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	int bll=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		bll|=c[i];
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
			bll|=d[i][j];
		}
	}
	if(bll==0){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int sum=0;
	for(int i=1;i<=m;i++){
		int sx=a[i].x,sy=a[i].y,sz=a[i].z;
		int fx=fa(sx),fy=fa(sy);
		if(fx!=fy){
			f[fx]=fy;
			sum++;
			int hk=0;
			long long minx=3e9+10;
			long long mina=3e9+10;
			for(int j=1;j<=k;j++){
				if(d[j][a[i].x]+d[j][a[i].y]+c[j]<minx||(d[j][a[i].x]+d[j][a[i].y]+c[j]==minx&&d[j][a[i].x]+d[j][a[i].y]<mina)){
					minx=d[j][a[i].x]+d[j][a[i].y]+c[j];
					mina=d[j][a[i].x]+d[j][a[i].y];
					hk=j;
				}
			}
			if(d[hk][a[i].x]+d[hk][a[i].y]+c[hk]<=sz){
				ans+=d[hk][a[i].x]+d[hk][a[i].y]+c[hk];
				c[hk]=0;
			}
			else if(d[hk][a[i].x]+d[hk][a[i].y]<sz&&d[hk][a[i].x]+d[hk][a[i].y]+c[hk]>=sz){
				hd[hk][1]+=sz;
				hd[hk][2]+=d[hk][a[i].x]+d[k][a[i].y];
			}
			else{
				ans+=sz;
			}
			if(sum==n-1){
				break;
			}
		}
	}
	for(int i=1;i<=k;i++){
		ans+=min(hd[i][1],hd[i][2]+c[i]);
	}
	cout<<ans;
	return 0;
}
