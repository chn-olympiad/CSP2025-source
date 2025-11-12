#include<bits/stdc++.h>
using namespace std;
int n,a[4],num,x;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	x=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]>x)x=a[i];
		num+=a[i];
	}
	if(2*x<num)cout<<1;
	else cout<<0;
	return 0;
}
