#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int x[N],y[N],z[N],ans,n;
void dfs(int u,int c1,int c2,int c3,int sum){
	if(u==n){
		ans=max(ans,sum);
		return;
	}
	if(c1+1<=n/2)dfs(u+1,c1+1,c2,c3,sum+x[u+1]);
	if(c2+1<=n/2)dfs(u+1,c1,c2+1,c3,sum+y[u+1]);
	if(c3+1<=n/2)dfs(u+1,c1,c2,c3+1,sum+z[u+1]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int f=1;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
			if(y[i]!=0||z[i]!=0)f=0;
		}
		if(f){
			sort(x+1,x+n+1);
			for(int i=n;i>=n/2+1;i--)ans+=x[i];
			cout<<ans<<endl;
		}
		else{
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
