#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],b[100005],c[100005],t,n,ans=0,p[4];
void dfs(int m,int cnt){
	if(m>n){
		ans=max(ans,cnt);
		return ;
	}
	if(p[1]<n/2){
		p[1]++;
		dfs(m+1,cnt+a[m]);
		p[1]--;
	}
	if(p[2]<n/2){
		p[2]++;
		dfs(m+1,cnt+b[m]);
		p[2]--;
	}
	if(p[3]<n/2){
		p[3]++;
		dfs(m+1,cnt+c[m]);
		p[3]--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(p,0,sizeof p);
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}