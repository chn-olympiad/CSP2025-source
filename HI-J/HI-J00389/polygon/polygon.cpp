#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,x=0;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	if(n<=3) {
		if(n==1 || n==2) cout<<0;
		else {
			sort(a,a+3);
			cout<<a[0]<<a[1]<<a[2]<<endl;
			if(a[2]+a[1]>=2*a[0]) x++;
			if(a[0]+a[1]>=2*a[2]) x++;
			if(a[2]+a[0]>=2*a[1]) x++;
			cout<<x;
		}
		return 0;
	}
	cout<<0;
	return 0;
}
