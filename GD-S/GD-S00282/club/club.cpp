#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define per(i,a,n) for(int i=(n);i>=(a);--i)
#define SZ(x) ((int)x.size())

using namespace std;

typedef long long ll;

const int maxn=1e5+10;

int n,m,mxid[maxn],cnt[3],a[maxn][3],b[maxn];

inline void solve(){
	scanf("%d",&n);
	rep(i,0,2) cnt[i]=0;
	m=0;
	int res=0;
	rep(i,1,n){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);	
		int mx=max({a[i][0],a[i][1],a[i][2]});
		res+=mx;
		if(a[i][0]==mx) cnt[0]++,mxid[i]=0;
		else if(a[i][1]==mx) cnt[1]++,mxid[i]=1;
		else cnt[2]++,mxid[i]=2;
	}
	int id=-1;
	rep(i,0,2){
		if(cnt[i]>n/2) id=i;
	}	
	if(id!=-1){
		int p=cnt[id]-n/2;
		rep(i,1,n){
			if(mxid[i]!=id) continue;
			int mx=0;
			rep(j,0,2){
				if(j==id) continue;
				mx=max(mx,a[i][j]);
			}
			b[++m]=mx-a[i][mxid[i]];
		}	
		sort(b+1,b+1+m);
		rep(i,m-p+1,m) res+=b[i];
	}
	printf("%d\n",res);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _=1;
	scanf("%d",&_);
	while(_--) solve();
} 
