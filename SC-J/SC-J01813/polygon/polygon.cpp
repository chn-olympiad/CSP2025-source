#include<bits/stdc++.h>
using namespace std;
long long f(int x){
	long long sum=0;
	for(int i=1;i<=x;i++){
		sum=(sum+i)%998244353;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	long long n,a[10005]={},flag=1,ans=1,sum=0,maxn=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		if(sum>maxn*2) cout<<1;
		else cout<<0;
		return 0;
	}
	if(flag==1){
		for(int i=n-2;i>=2;i--){
			ans=(ans+f(i))%998244353;
		}
		cout<<ans;
		return 0;
	}
    cout<<maxn;    
	return 0;
}