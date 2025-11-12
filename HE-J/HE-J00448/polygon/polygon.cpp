#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if((a[1]+a[2]+a[3])>2*max(a[1],max(a[2],a[3]))){
		cout<<1%998244353;
	}
	return 0;
}
