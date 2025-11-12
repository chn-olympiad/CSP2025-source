#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3||2*max(a[1],max(a[2],a[3]))>=a[1]+a[2]+a[3]){
		cout<<"0";
	}
	else{
	cout<<"1";
	}
	return 0;
}
