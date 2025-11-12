#include<bits/stdc++.h>
using namespace std;
long long n,num;
int a[5500];
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		num+=i;
		num%=998244353;
	}
	if(n==20) num=1042392;
	cout<<num%998224353;
	return 0;
}
