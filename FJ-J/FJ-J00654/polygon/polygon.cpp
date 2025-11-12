#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,a[100010],ans;
long long f(long long x){
	long long sum=1,a=2;
	while(x>0){
		if(x&1)sum=(sum*a)%mod;
		a=(a*a)%mod,x>>=1;
	}
	return sum;
}
void dfs(long long l,long long r,long long num,long long sum,long long minn){
	if(num>=3&&sum>minn){
		ans=(ans+f(r-l+1))%mod;
		return;
	}
	if(l>r)return;
	for(int i=l;i<=r;i++){
		dfs(i+1,r,num+1,sum+a[i],minn);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(1,i-1,1,0,a[i]);
	}
	cout<<ans; 
	return 0;
}
