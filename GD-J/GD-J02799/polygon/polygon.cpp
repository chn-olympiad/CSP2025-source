#include<bits/stdc++.h>
using namespace std;
int n,a[5007];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool f = 1;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1)f = 0;
	}if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),max(a[2],a[3]))){
			cout << 1;
		}else{
			cout << 0;
		}return 0;
	}if(f){
		long long ans = 0;
		for(int i = 3;i<=n;i++){
			long long p = 1,q = 1,r = 1;
			for(int j = 1;j<=i;j++){
				p*=n-j+1;
				q*=j;
			}ans+=p/q%998244353;
		}cout << ans;
		return 0;
	}
	return 0;
} 
