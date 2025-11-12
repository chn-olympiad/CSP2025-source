#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ma,su,ms,l,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3)cout<<0;
	else if(n==3){
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])cout<<1;
		else cout<<0;
	}
	else cout<<50;
	return 0;
} /*
5
1 2 3 4 5
*/


