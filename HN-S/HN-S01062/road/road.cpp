#include<bits/stdc++.h> 
#define int long long
using namespace std;
inline int read(){int x = 0,ch = getchar();bool zt=0;while(ch<48||ch>57){if(ch==45)zt = 1;ch = getchar();}while(ch>=48&ch<=57){x = (x<<3)+(x<<1)+(ch^48);ch = getchar();}return zt?-x:x;}
const int N = 1e4 + 100,M = 1e6 + 10;
int n,m,K,ans = 1e18,d[N],sz[N],fa[N];
struct A{int x,y,z,id;}a[M+N*10];
int find(int x){return fa[x]==x?x:fa[x] = find(fa[x]);}
bool cmp(A x,A y){return x.z<y.z;}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();m = read();K = read();bool zt = 0,zt1 = 0;
	for(int i=1;i<=m;i++)a[i] = {read(),read(),read(),0};
	for(int i=1;i<=K;i++){d[i] = read();zt |= d[i];zt1 |= d[i]; 
		for(int j=1;j<=n;j++)m++,a[m] = {i+n,j,read(),i},zt |= a[m].z;
	}sort(a+1,a+1+m,cmp);
	if(zt==0){cout<<0;return 0;}
	if(zt1==0){ans = 0;
		for(int i=1;i<=n+K;i++)fa[i] = i,sz[i] = 1;
		for(int i=1;i<=m;i++){
			A k = a[i];int x = k.x,y = k.y,z = k.z;
			int xx = find(x),yy = find(y);
			if(xx!=yy){
				sz[yy] += sz[xx];
				fa[xx] = yy;
				ans += z;
			}
			if(sz[yy]==n+K)break;
		}cout<<ans;return 0; 
	} 
	for(int j=0;j<=(1<<K)-1;j++){
		for(int i=1;i<=n+K;i++)fa[i] = i,sz[i] = 1;
		int sum = 0,s = 0;
		for(int i=1;i<=K;i++)if((j>>(i-1))&1)sum += d[i],s++;
//		cout<<j<<' '<<sum<<'\n';
		for(int i=1;i<=m;i++){
			A k = a[i];if(k.id!=0&&((j>>(k.id-1))&1)==0)continue;
			int x = k.x,y = k.y,z = k.z;
			int xx = find(x),yy = find(y);
			if(xx!=yy){
				sz[yy] += sz[xx];
				fa[xx] = yy;
				sum += z;
			}
//			cout<<x<<' '<<y<<' '<<z<<' '<<k.id<<' '<<xx<<' '<<yy<<' '<<sum<<'\n';
			if(sz[yy]==n+s)break;
		}ans = min(ans,sum);
//		cout<<sum<<' '<<ans<<'\n'; 
	} 
	cout<<ans;
	return 0;
}
