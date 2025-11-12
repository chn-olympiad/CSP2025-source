#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],ans,n,c[5005][5005];
void dfs(int wz,int sum,int k){
	for(int i=wz+1; i<=n; i++){
		sum+=a[i];
		if(k>=3){
			if(sum>2*a[i]) ans=(ans+1)%998244353;
		}
		dfs(i,sum,k+1);
		sum-=a[i];
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; int mx=-1;
	for(int i=1; i<=n; i++) cin>>a[i],mx=max(a[i],mx);
	sort(a+1,a+n+1);
	if(mx!=1) dfs(0,0,1);
	else{
		ans=0;
		for(int i=1; i<=n; i++){
			for(int j=0; j<=i; j++){
				if(j==i || j==0) c[i][j]=1;
				else c[i][j]=(c[i-1][j]+c[i-1][j-1])%998244353;
			}
		}
		for(int i=3; i<=n; i++){
			ans=(ans+c[n][i])%998244353;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

