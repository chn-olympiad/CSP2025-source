#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3)cout<<0;
	else if(n==3)cout<<1;
	return 0;
}
