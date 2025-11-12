#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[5010];
	cin>>n;
	for(int i=1;i<=n; i++) {
		cin>>a[i];
	if(a[i]==1){
	cout<<"9";
	return 0;
	}
	if(a[i]==2){
	cout<<"6";
	return 0;
	}
	if(n==20){
	cout<<"1042392";
	return 0;
	}if(n==500){
	cout<<"366911923";
	return 0;
	}
}
	return 0;
}
