#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],b[5005];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]) swap(a[i],a[j]);	
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(b[n]>2*a[1]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(a[1]==1){
		for(int i=3;i<=n;i++){
			long long x=1,y=1;
			for(int j=1;j<=i;j++){
				x*=(n-j+1);
				y*=j;
				
			}
			cout<<x<<" "<<y<<endl;
			long long k=x/y;
			
			ans=(ans+k)%998244353;
		}
		cout<<ans;
	}
	return 0;
}
