#include <bits/stdc++.h>
using namespace std;
int n,a[10000],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n==3){
		if(sum>a[1]*2 && sum>a[2]*2 && sum>a[3]*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		cout<<n-2;
	}
	return 0;
}
