#include<bits/stdc++.h>
using namespace std;
#define V vector
#define ll long long
#define ull unsigned long long
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define pb push_back
const int INF=1e9+10;
struct node{
	int a,b,c;
};
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		V<node>a(n+1);
		FOR(i,1,n){
			cin>>a[i].a>>a[i].b>>a[i].c;
		} 
		V<V<V<V<int> > > >dp(n+1,V<V<V<int> > >(n/2+1,V<V<int> >(n/2+1,V<int>(n/2+1,0))));
		FOR(i,1,n){
			FOR(j,0,i){
				if(j>n/2) break;
				FOR(k,0,i){
					if(k>n/2) break;
					int l=i-j-k;
					if(l>n/2) continue;
					if(l<0) break;
					int &d=dp[i][j][k][l];
					if(j!=0) d=max(d,dp[i-1][j-1][k][l]+a[i].a);
					if(k!=0) d=max(d,dp[i-1][j][k-1][l]+a[i].b);
					if(l!=0) d=max(d,dp[i-1][j][k][l-1]+a[i].c);
				}
			}
		}
		int ans=0;
		FOR(i,0,n/2){
			FOR(j,0,n/2){
				int k=n-i-j;
				if(k>n/2) continue;
				if(k<0) break;
				ans=max(ans,dp[n][i][j][k]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
