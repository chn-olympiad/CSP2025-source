#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int a[100],x=1,y=2,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if((a[1]+a[2])>a[3]&&(a[1]+a[2])>a[4]&&(a[1]+a[3])>a[4]&&(a[3]+a[2])>a[4]){
		cout<<4;
		return 0;
	}
	if((a[1]+a[2])>a[3]&&(a[1]+a[2])>a[4]&&(a[1]+a[3])>a[4]){
		cout<<3;
		return 0;
	}
	if((a[1]+a[2])>a[3]&&(a[1]+a[2])>a[4]&&(a[3]+a[2])>a[4]){
		cout<<3;
		return 0;
	}
	if((a[1]+a[2])>a[3]&&(a[1]+a[3])>a[4]&&(a[3]+a[2])>a[4]){
		cout<<3;
		return 0;
	}
	if((a[1]+a[2])>a[4]&&(a[1]+a[3])>a[4]&&(a[3]+a[2])>a[4]){
		cout<<3;
		return 0;
	}
	if((a[1]+a[2])>a[3]&&(a[1]+a[2])>a[4]){
		cout<<2;
		return 0;
	}
	if((a[1]+a[2])>a[3]&&(a[3]+a[2])>a[4]){
		cout<<2;
		return 0;
	}
	if((a[1]+a[3])>a[4]&&(a[3]+a[2])>a[4]){
		cout<<2;
		return 0;
	}
	if((a[1]+a[3])>a[4]&&(a[3]+a[2])>a[4]){
		cout<<2;
		return 0;
	}
	if((a[3]+a[2])>a[4]){
		cout<<1;
		return 0;
	}
	if((a[1]+a[3])>a[4]){
		cout<<1;
		return 0;
	}
	if((a[1]+a[2])>a[4]){
		cout<<1;
		return 0;
	}
	if((a[1]+a[2])>a[3]){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
} 

