#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans,c[5010][10];
void dfs(long long x,long long Max,long long sum,long long cnt){
	if(x>n){
		if(cnt>=3&&sum>2*Max){
			ans=(ans+1)%998244353;
		}
		return;
	}
	dfs(x+1,Max,sum,cnt);
	dfs(x+1,max(Max,a[x]),sum+a[x],cnt+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	else{
		for(int i=0;i<=n;i++){
			c[i][0]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				c[i][j]=(c[i-1][j]+c[i-1][j-1])%998244353;
			}
		}
		cout<<c[n][3];
		return 0;
	}
	return 0;
}
