#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans,mod=998244353,b[5010],y[5010][5010];
void dfs(int x,int sum,int maxx){
	for(int i=x;i>=1;i--){
		sum+=a[i];
		if(sum>maxx){
			ans=(ans+b[i])%mod;
			sum-=a[i];
			continue;
		}
		dfs(i-1,sum,maxx);
		sum-=a[i];
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	y[1][1]=1,b[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			y[i][j]=y[i-1][j]+y[i-1][j-1];
			b[i]+=y[i][j];
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=3;i--){
		dfs(i-1,0,a[i]);
	}
	cout<<ans;
	return 0;
}