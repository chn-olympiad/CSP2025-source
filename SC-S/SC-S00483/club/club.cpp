#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans=0;
struct ya{
	int y,r,s;
}a[100005];
void dfs(int n,int i,ll sum,int g1,int g2,int g3){
	if(i==n){
		ans=max(ans,sum);
		return;
	}
	if(g1<n/2){
		dfs(n,i+1,sum+a[i].y,g1+1,g2,g3);
	}
	if(g2<n/2){
		dfs(n,i+1,sum+a[i].r,g1,g2+1,g3);
	}
	if(g3<n/2){
		dfs(n,i+1,sum+a[i].s,g1,g2,g3+1);
	}
}

int n,t,y,r,s;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		y=0;r=0;s=0;ans=0;
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i].y>>a[i].r>>a[i].s;
		dfs(n,0,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}