#include<bits/stdc++.h>
using namespace std;
const int maxn=210,N=1e5+10;
int dp[maxn][maxn][maxn],ans;
int t,n,fa,fb;
struct pe {
	int a,b,c;
} r[N];
bool cmp1(pe a,pe b) {
	return a.a>b.a;
}
void init() {
	ans=0;
	fa=fb=1;
	memset(dp,0,sizeof dp);
}
void in() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>r[i].a>>r[i].b>>r[i].c;
		if(r[i].b!=0||r[i].c!=0)fa=0;
		if(r[i].c!=0)fb=0;
	}
}
void super_dp() {
	for(int p=1; p<=n; p++) {
		for(int i=0; i<= (n>>1); i++) {
			for(int j=0; j<=(n>>1); j++) {
				if((i+j)>p||(p-i-j)>(n>>1))continue;
				int k=p-i-j;
				dp[i][j][k]=max(dp[max(i-1,0)][j][k]+r[p].a*(i>=1),max(dp[i][max(j-1,0)][k]+r[p].b*(j>=1),dp[i][j][max(k-1,0)]+r[p].c*(k>=1)));
//				cout<<p<<" "<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
				if(p==n)ans=max(ans,dp[i][j][k]);
			}
		}
	}

}
void solve_a() {
	sort(r+1,r+1+n,cmp1);
	for(int i=1; i<=(n>>1); i++) {
		ans+=r[i].a;
	}
}
void solve_b() {
	
}
int main() {
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		init();
		in();
		if(n<=200) {
			super_dp();
		} else if(fa) {
			solve_a();
		}
//		else if(fb){
//			solve_b();
//		}
		cout<<ans<<"\n";
	}
	return 0;
}
