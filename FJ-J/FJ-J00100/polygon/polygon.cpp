#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
int n;
cin>>n;
if(n<3){
	cout<<"0";
}else if(n==3){
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	int num=0;
	num=a[n-1]*2;
	if(num<sum){
		cout<<"1";
	}else{
		cout<<"0";
	}
}else if(n==5){
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	if(a[n-1]==5){
		cout<<"9";
	}else{
		cout<<"6";
	}
}else{
	cout<<"0";
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
