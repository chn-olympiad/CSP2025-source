#include<bits/stdc++.h>
using namespace std;
int n;
const long long mod = 998244353;
long long a[5101];
long long f[5101][5101];
long long t[5010];
/*
long long dfs(int k,int rt){
	for(int i=1;;i++)
}*/
long long dfs(int x,int k,int sum,int rt){
	if(sum>a[rt]&&k>=2){
		//cout<<k<<' '<<sum<<'\n';
		return 1;
		}
		//cout<<x<<' ';
	for(int i=x+1;i<rt;i++){
		return dfs(i,k+1,sum+a[i],rt)+dfs(i,k,sum,rt);
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long ans=0;
	cin>>n;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(!f){
		for(int i=3;i<=n;i++){
			long long x=1,y=1;
			for(int j=n;j>=n-i+1;j--){
				x*=j;
				x%=mod;
			}
			for(int j=1;j<=i;j++){
				y*=j;
				y%=mod;
			}
			ans+=x/y;
			ans%=mod;
			//cout<<x<<' '<<y<<' '<<ans<<'\n';
		}
		cout<<ans;
	}else {
		for(int i=3;i<=n;i++){
			ans+=dfs(0,0,0,i);
			ans%=mod;
			//cout<<ans<<'\n';
		}
		cout<<ans;
		/*srot(a+1,a+n+1);
		for(int i=3;i<=n;i++){
			ans+=dfs(i);
			ans%=mod;
		}
		cout<<ans;*/
		//for(int i=1;i<=n;i++)if(a[i-1]!=a[i])t[a[i]]=i;
		/*for(int i=3;i<=n;i++){
			int k=a[i];
			for(int j=1;j<=;j++){
				for(){

				}
			}
		}*/
	}
	return 0;
}
