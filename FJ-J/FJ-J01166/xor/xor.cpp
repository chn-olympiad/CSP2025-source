#include <bits/stdc++.h>
#define int long long
#define y0 __Y0
#define y1 __y1
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define file(x) freopen(x".in","r",stdin);
using namespace std;
const int N=1e3+5;
int n,k,a[N],f[N][N],sum[N],ans;
vector<pii> g;
set<pii> s;
signed main(){
	FILE("xor")
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;cin>>a[1];sum[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				f[i][j]=a[i];
			}
			else{
				f[i][j]=sum[j]^sum[i-1];
			}
			if(f[i][j]==k){
				g.pb({i,j});
			}
		}
	}
	int m=g.size();
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			int l1=g[i].fi,r1=g[i].se;
			int l2=g[j].fi,r2=g[j].se;
			if(l1>=l2&&r1<=r2){
				swap(l1,l2);swap(r1,r2);
			}
			if((l1<l2 && r1>r2) || (l2<r1)){
				continue;
			}
			s.insert({l1,r1});s.insert({l2,r2});
		}
	}
	cout<<s.size();
	return 0;
}
