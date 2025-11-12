#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5]={0};
	int b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if((a[2]+a[3]+a[4])>a[4]*2){
		b++;
	}
	if((a[5]+a[3]+a[4])>a[5]*2){
		b++;
	}
	if((a[2]+a[5]+a[4])>a[5]*2){
		b++;
	}
	if((a[1]+a[2]+a[3]+a[4])>a[4]*2){
		b++;
	}
	if((a[1]+a[2]+a[3]+a[5])>a[5]*2){
		b++;
	}
	if((a[1]+a[2]+a[5]+a[4])>a[5]*2){
		b++;
	}
	if((a[1]+a[5]+a[3]+a[4])>a[5]*2){
		b++;
	}
	if((a[5]+a[2]+a[3]+a[4])>a[5]*2){
		b++;
	}
	if((a[1]+a[2]+a[3]+a[4]+a[5])>a[5]*2){
		b++;
	}
	if((a[2]+a[3]+a[1])>a[3]*2){
		b++;
	}
	if((a[5]+a[3]+a[4])>a[10]*2){
		b++;
	}
	if((a[2]+a[1]+a[4]+a[5])>a[10]*2){
		b++;
	}
	if((a[3]+a[1]+a[4]+a[5])>a[10]*2){
		b++;
	}
	if((a[2]+a[3]+a[4]+a[5])>a[10]*2){
		b++;
	}
	if((a[2]+a[1]+a[4]+a[5]+a[3])>a[10]*2){
		b++;
	}
	cout<<b%998244353;
	return 0;
}
