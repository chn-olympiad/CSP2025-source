#include<bits/stdc++.h>
using namespace std;

const int N=5100,mod=998244353;
int n,a[N],ans,c[N][N];

void dfs(int step,int num,int sum){
	if(num>=3){
		if(a[step]*2<sum) ans=(ans+1)%mod;
	}
	for(int i=step+1;i<=n;i++)
		dfs(i,num+1,sum+a[i]);
}

void init(){
	for(int i=1;i<=5050;i++) c[i][1]=i;
	for(int i=2;i<=5050;i++)
		for(int j=2;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag==1){
		init();
		for(int i=3;i<=n;i++) ans=(ans+c[n][i])%mod;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
