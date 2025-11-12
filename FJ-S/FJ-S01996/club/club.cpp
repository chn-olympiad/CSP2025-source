// I Love CCF
// CSP-S 1=
// CSP-S 1=
// CSP-S 1=
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mkp make_pair
#define pll pair<ll,ll>
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
int T,n,a[100005][5];
ll f[205][205][205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		int mx=(n>>1);
		bool flaga=1;
		rep(i,1,n){
			rep(j,1,3){
				scanf("%d",&a[i][j]);
			}
			if(a[i][2]!=0||a[i][3]!=0)flaga=0;
		}
		if(flaga){
			priority_queue<int> q;
			rep(i,1,n){
				q.push(a[i][1]);
			}
			ll ans=0;
			rep(i,1,mx){
				ans+=q.top();
				q.pop();
			}
			printf("%lld\n",ans);
			continue;
		}
		rep(i,1,n){
			rep(j,0,mx){
				rep(k,0,mx){
					if(j+k>i)continue;
					if(i-j-k>mx)continue;
					f[i][j][k]=0;
					if(j>0)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
					if(k>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
					if(i-j-k>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
				}
			}
		}
		ll ans=0;
		rep(i,0,mx){
			rep(j,0,mx){
				if(i+j>n)continue;
				if(n-i-j>mx)continue;
				ans=max(ans,f[n][i][j]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
// I Love CCF
