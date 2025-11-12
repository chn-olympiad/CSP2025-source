#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum,maxn;
void dfs(int c,int xg,long long maxx,long long zh,int xxg){
	if(xg>n+1){
		return;
	}
	if(c>=3&&maxx*2<zh&&xxg){
		sum=(sum+1)%998244353;
	}
	dfs(c+1,xg+1,max(maxx,a[xg]),zh+a[xg],1);
	dfs(c,xg+1,maxx,zh,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		if(maxn*2>a[1]+a[2]+a[3]){
			cout<<0;
		}else{
			cout<<1;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,1,0,0,0);
	cout<<sum;
	return 0;
}
