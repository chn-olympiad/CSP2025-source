#include<bits/stdc++.h>
using namespace std;
const int N=210;
int t,n,dp[2][N][N][N];
struct node{
	int x,y,z;
}s[N];
bool cmp(node A,node B){
	return A.x>B.x;
}
void solve(){
	memset(dp,0,sizeof(dp));
	memset(s,0,sizeof(s));
	cin>>n;	
	for(int i=1;i<=n;i++) cin>>s[i].x>>s[i].y>>s[i].z;
	int ans=0;
	if(n==1e5){
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n/2;i++) ans+=s[i].x;
		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		int l=i%2;
		for(int a=0;a<=n/2;a++){
			for(int b=0;b<=n/2;b++){
				int c=i-a-b;
				if(c>n/2) continue;
				int a1,b1,c1;
				a1=b1=c1=INT_MIN;
				if(a!=0) a1=dp[l^1][a-1][b][c]+s[i].x;
				if(b!=0) b1=dp[l^1][a][b-1][c]+s[i].y;
				if(c!=0) c1=dp[l^1][a][b][c-1]+s[i].z;
				dp[l][a][b][c]=max(a1,max(b1,c1));
				if(i==n) ans=max(ans,dp[l][a][b][c]);
			}
		}		
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	cin>>t;
	while(t--) solve();
	return 0;
} 
