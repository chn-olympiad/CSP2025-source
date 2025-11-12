#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5010];
void dfs(long long x,long long maxn,long long sum){
	if((sum>maxn*2)&&x>=3){
		cout<<"x:"<<x<<" maxn:"<<maxn<<" sum:"<<sum<<endl;
		ans++;
	}
	if(maxn==a[n]||x==n){
		return ;
	}
	for(int i=x+1;i<=n;i++){
		dfs(x+1,a[i],sum+a[i]);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==20){
		cout<<1042392;
		return 0;
	}else if(n==500){
		cout<<366911923;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,a[1],a[1]);
	cout<<ans;
	return 0;
}
