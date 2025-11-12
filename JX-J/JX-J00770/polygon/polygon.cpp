#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100005];
long long f(int x,int c,int i){
	if(x==1){
		long long ans=0;
		for(int j=i;j<=n;j++){
			if(a[j]<c)ans++;
		}
		return ans;
	}
	else{
		long long ans=0;
		for(int j=i;j<=n-x+1;j++){
			ans=(ans+f(x-1,a[j]+c,j+1))%998244353;
		}
		return ans;
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1])cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=3;i<=n;i++){
		long long x=f(i,0,1)%998244353;
		//cout<<x<<" ";
		ans=(ans+x)%998244353;
	}
	cout<<ans;
	return 0;
}
