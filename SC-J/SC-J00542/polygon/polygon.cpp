#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int n;
int s=3;
int cnt;
int sum;
void f1(int n){
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
}
void f2(int n){
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==0||n==1||n==2){
		cout<<0;
			
	} 
	if(n==3){
		
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<1;
		}else{
			cout<<0;
		}
		
	}
	if(n==4){
		cnt=0;
		if(a[1]+a[2]+a[3]>a[3]*2) cnt++;
		if(a[1]+a[2]+a[4]>a[4]*2) cnt++;
		if(a[4]+a[2]+a[3]>a[4]*2) cnt++;
		if(a[1]+a[4]+a[3]>a[4]*2) cnt++;
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) cnt++;
		cout<<cnt;
		
	}
	if(n==5){
		cnt=0;
		if(a[1]+a[2]+a[3]>a[3]*2) cnt++;
		if(a[1]+a[2]+a[4]>a[4]*2) cnt++;
		if(a[1]+a[4]+a[3]>a[4]*2) cnt++;
		if(a[4]+a[2]+a[3]>a[4]*2) cnt++;
		if(a[1]+a[2]+a[5]>a[5]*2) cnt++;
		if(a[1]+a[5]+a[3]>a[5]*2) cnt++;
		if(a[5]+a[2]+a[3]>a[5]*2) cnt++;
		if(a[5]+a[2]+a[4]>a[5]*2) cnt++;
		if(a[5]+a[4]+a[3]>a[5]*2) cnt++;
		if(a[1]+a[4]+a[5]>a[5]*2) cnt++;
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) cnt++;
		if(a[1]+a[2]+a[3]+a[5]>a[5]*2) cnt++;
		if(a[5]+a[2]+a[3]+a[4]>a[5]*2) cnt++;
		if(a[1]+a[2]+a[5]+a[4]>a[5]*2) cnt++;
		if(a[1]+a[5]+a[3]+a[4]>a[5]*2) cnt++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2) cnt++;
		cout<<cnt;
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>3){
		f2(n);
	}else{
		f1(n);
	}
	
	return 0;
}
/*
5
1 2 3 4 5
5
2 2 3 8 10

*/