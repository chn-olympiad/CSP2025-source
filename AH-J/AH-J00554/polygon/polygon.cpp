#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
long long f[5005];
long long C(int a,int b){
	long long c1=1,c2=1;
	for(int i=a;i>=a-b;i--){
		c1*=i;c1%=998244353;
	}for(int i=1;i<=b;i++){
		c2*=i;c2%=998244353;
	}return c1/c2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}if(n<=3)
	for(int i=3;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			if(a[j+i]*2<f[j+i]-f[j]){
				ans++;cout<<a[i+j]<<" "<<f[j+i]-f[j]<<endl;
			}
		}
	}
	else{
		for(int i=3;i<=n;i++){
			ans+=C(n,i);
		}ans++;
	}
	
	cout<<ans%998244353;
}
