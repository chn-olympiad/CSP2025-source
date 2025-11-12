#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		vector<int>a(n+1),b(n+1),c(n+1);
		vector<int>chos(n+1);
		int d=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			a[i]-=c[i];
			b[i]-=c[i];
			d+=c[i];
			c[i]=0;
		}
		int ans=-1e14;
		int tle=0;
		auto dfs=[&](int x,int t1,int t2,int t3,auto&&dfs)->void{
			if(t1>n/2||t2>n/2||t3>n/2)return;
			tle++;
			if(tle>=3e6)return;
			if(x==n+1){
				int g=0;
				for(int i=1;i<=n;i++){
					if(chos[i]==1)g+=a[i];
					if(chos[i]==2)g+=b[i];
				}
				ans=max(ans,g);
				return;
			}	
			chos[x]=1;
			dfs(x+1,t1+1,t2,t3,dfs);
			chos[x]=2;
			dfs(x+1,t1,t2+1,t3,dfs);
			chos[x]=3;
			dfs(x+1,t1,t2,t3+1,dfs);
		};
		dfs(1,0,0,0,dfs);
		cout<<ans+d<<endl;
	}
}