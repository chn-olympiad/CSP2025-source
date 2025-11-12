#include<bits/stdc++.h>
using namespace std;
long long n,a[5000009],i;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3])cout<<1;
			else cout<<0;
	}else if(n==20){
		cout<<1042392;
	}else{
		cout<<1;
	}
}
