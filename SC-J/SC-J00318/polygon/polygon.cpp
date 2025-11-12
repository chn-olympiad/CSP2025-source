#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],mx;
long long fl(long long sz){
	long long ans=0;
	for(int i=n;i>=3;i--){
		long long cnt=1;
		for(int j=n;j>n-i;j--) cnt=(cnt*j)%998244353;
		for(int j=1;j<=i;j++) cnt=(cnt/j)%998244353;
		ans+=cnt;
//		cout<<cnt<<" ";
	}
	return ans;
}
long long f(long long k,long long sum,long long mxx,long long z){
	if(k==n+1) return z>=3&&sum>mxx*2;
	long long num=0;
	num=(num+f(k+1,sum,mxx,z))%998244353,num=(num+f(k+1,sum+a[k],max(mxx,a[k]),z+1))%998244353;
//	cout<<k<<" "<<num<<" "<<sum<<"\n"; 
	return num;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
	if(mx==1){
		cout<<fl(n);
		return 0;
	}
	cout<<f(1,0,0,0);
	return 0;
}
