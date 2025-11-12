#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long ans,n,a[5005];
long long f(int depth,long long sum,long long pos,long long max1){
	if(depth==0){
//		cout<<sum<<" "<<max1<<" ";
		if(sum>2*max1){
			return 1;
		}else{
			return 0;
		}
	}
	int num=0;
	for(int i=pos;i<=n-depth+1;i++){
		num+=f(depth-1,sum+a[i],i+1,max(max1,a[i]))%MOD;
		num%=MOD;
	}
	return num%MOD;
}
int main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(flag){
		for(int i=3;i<=n/2;i++){
			long long cnt=1;
			for(int j=1;j<=i;j++){
				cnt*=(n-j);
				cnt%=MOD;
			}
			ans+=cnt;
			ans%=MOD;
		}
		for(int i=n/2+1;i<=n;i++){
			long long cnt=1;
			for(int j=1;j<=n-i+1;j++){
				cnt*=(n-j);
				cnt%=MOD;
			}
			ans+=cnt;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=n;i++){
		ans+=f(i,0,1,0)%MOD;
		ans%=MOD;
	}
	cout<<ans%MOD;
	return 0;
}
