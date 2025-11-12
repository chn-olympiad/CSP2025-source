#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>

using namespace std;

const int maxn=1e6+10;
const int inf=0x3f3f3f3f;

int n;
int dp[maxn],cnt1[maxn],cnt2[maxn],cnt3[maxn];
struct node{
	int x,y,z;
} a[maxn];

void solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y>>a[i].z;
		dp[i]=cnt1[i]=cnt2[i]=cnt3[i]=0;
	}
	
	for(int i=n/2;i>=0;--i){
		
		for(int j=1;j<=n;++j){
			int m;
			
			if(cnt1[j-1]<=i-1 && dp[j-1]+a[j].x>dp[j]){
				dp[j]=dp[j-1]+a[j].x;
				m=1;
			}
			
			if(cnt2[j-1]<=i-1 && dp[j-1]+a[j].y>dp[j]){
				dp[j]=dp[j-1]+a[j].y;
				m=2;
			}
			
			if(cnt3[j-1]<=i-1 && dp[j-1]+a[j].z>dp[j]){
				dp[j]=dp[j-1]+a[j].z;
				m=3;
			}
			
			if(m==0) dp[j]=dp[j-1];
			else if(m==1) cnt1[j]=cnt1[i-1]+1;
			else if(m==2) cnt2[j]=cnt2[i-1]+1;
			else if(m==3) cnt3[j]=cnt3[i-1]+1;
			
		}
	}
	
	cout<<dp[n]<<'\n';
	return ;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int T;
	cin>>T;
	
	while(T--){
		solve();
	}
	return 0;
} 
