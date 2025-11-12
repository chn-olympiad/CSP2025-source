#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans=-1,a[N],b[N],c[N];
void dfs(int now,int asum,int bsum,int csum,int sum){
	if(asum>n/2 || bsum>n/2 || csum>n/2)return;
	if(now>=n){
		ans=max(ans,sum);
		return;
	}
	dfs(now+1,asum+1,bsum,csum,sum+a[now+1]);
	dfs(now+1,asum,bsum+1,csum,sum+b[now+1]);
	dfs(now+1,asum,bsum,csum+1,sum+c[now+1]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
		ans=-1;
	}
	
	return 0;
}
