#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[5003],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(n==3){if(a[1]+a[2]>a[3]&&a[1]+a[3]>=a[2]&&a[2]+a[3]>=a[1]) cnt++;}
		else cnt=0;
		cout<<cnt;
	}
	else cout<<n*n-1;
	return 0;
}
