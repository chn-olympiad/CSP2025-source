#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+100;
ll n,ans;
int a[N],b[N],c[N];
ll d[N];
void dfs(int k,ll sum,int si,int x,int y,int z){
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	int i=si+1;
	if(d[n]-d[i-1]+sum<=ans) return;
	if(x<n/2) dfs(k+1,sum+a[i],i,x+1,y,z);
	if(y<n/2) dfs(k+1,sum+b[i],i,x,y+1,z);
	if(z<n/2) dfs(k+1,sum+c[i],i,x,y,z+1);
}
void solve(){
	cin>>n;
	ans=0;
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	memset(d,0,sizeof d);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		d[i]=d[i-1]+max(a[i],max(b[i],c[i]));
	}
	dfs(1,0,0,0,0,0);
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
