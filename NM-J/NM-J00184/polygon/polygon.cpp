#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010],b[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	if(n<3){
		cout<<0%998244353;
	}
	if(n==3){
		if(2*b[2]<=b[3]){
			cout<<0%998244353;
		}
		else if(2*b[2]>b[3]){
			cout<<1%998244353;
		}
	}
	else if(n>3){
		int num=0;
		for(int i=3;i<=n;i++){
			num=num+n*(n-i);
		}
		cout<<num%998244353;
	}
	return 0;
}
