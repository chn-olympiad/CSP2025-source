#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100006],vis[1000006];
int n,ans=0,ma=-1;
void dfs(int x){
	if(x==n+1){
		int sum=0,maxx=-1,num=0;
		for(int i = 1;i<=n;i++){
			if(vis[i]==1){
				sum+=a[i];
				maxx=max(maxx,a[i]);
				num++;
			}
		}if(sum>2*maxx&&num>=3) ans++;
		return;
	}vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}if(ma==1){
		ans=0;
		for(int i = 3;i<=n;i++){
			int bb=1,cc=1;
			for(int j = 1;j<=i;j++){
				bb=(bb*(n-j+1))%998244353;
				cc=(cc*j)%998244353;
			}ans+=(bb/cc);
		}cout<<(ans%998244353);
		return 0;
	}
	else dfs(1);
	cout<<(ans%998244353);
	return 0;
}

