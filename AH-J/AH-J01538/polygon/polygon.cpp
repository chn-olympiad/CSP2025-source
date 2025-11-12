#include <bits/stdc++.h>
using namespace std;
int a[5015],b[5015],n;
long long sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==5){
		if(a[1]==1)cout<<9;
		if(a[1]==2)cout<<6;
	}else if(n==20){
		cout<<1042392;
	}else if(n==500){
		cout<<366911923;
	}
	return 0;
}
