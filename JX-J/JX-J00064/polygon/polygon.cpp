#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,N=5e3+100;
long long n,a[N],cnt,ans,maxn;
long long solve(long long x){
	long long sum=1;
	for(int i=1;i<=x;i++)
		sum=(sum*i)%MOD;
	for(int i=n-x+1;i<=n;i++)
		sum=(sum*i)%MOD;
	cout<<1;
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)
			cnt++;
		maxn=max(a[i],maxn);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*maxn)
			cout<<1;
		else cout<<0;
		return 0;
	}
	if(cnt==n){
		ans=1;
		for(long long i=3;i<n;i++)
			ans=(ans+solve(i))%MOD;
		cout<<ans;
	}
	return 0;
}
