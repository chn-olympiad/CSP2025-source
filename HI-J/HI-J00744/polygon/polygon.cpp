#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n!=3) {
		cout<<0;
		return 0;
	}
	int t1,t2,t3;
	cin>>t1>>t2>>t3;
	int sum=t1+t2+t3;
	if((t1*2<sum&&t2*2<sum)&&t3*2<sum) {
		cout<<1;
	} else {
		cout<<0;
	}
	return 0;
}

