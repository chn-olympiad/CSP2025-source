#include<bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<"\n";
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pep(i,a,b) for(int i=(a);i>=(b);i--)
#define repp(i,a,b,s) for(int i=(a);i<=(b);i+=(s))
#define pepp(i,a,b,s) for(int i=(a);i>=(b);i-=(s))
using namespace std;
const int N=1e3+10;
int T,n,maxn,a[N][4];
void dfs(int u,int ans,int cnt1,int cnt2,int cnt3){
	if(u==n+1){
		maxn=max(maxn,ans);
		return ;
	}
	if(cnt1<n/2){
		dfs(u+1,ans+a[u][1],cnt1+1,cnt2,cnt3);
	}
	if(cnt2<n/2){
		dfs(u+1,ans+a[u][2],cnt1,cnt2+1,cnt3);
	}
	if(cnt3<n/2){
		dfs(u+1,ans+a[u][3],cnt1,cnt2,cnt3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		maxn=0;
		dfs(1,0,0,0,0);
		cout<<maxn<<"\n";
	}
	return 0;
}
