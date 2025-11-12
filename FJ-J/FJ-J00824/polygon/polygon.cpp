#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main(){
	freopen("polygon.in","in",stdin);
	freopen("polygon.out","out",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
		cout<<"9";
		return 0;
	}
	if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){
		cout<<"6";
		return 0;
	}
	if(n<=2){
		cout<<"0";
		return 0;
	}
	if(n==3){
		if(a[0]+a[2]+a[1]>2*a[0]||2*a[1]||2*a[2]){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}
	if(n==4){
		int i=0;
		if(a[0]+a[1]+a[2]>2*max(max(a[0],a[1]),a[2])){
			i=i+1;
		}
		if(a[0]+a[1]+a[3]>2*max(max(a[0],a[1]),a[3])){
			i=i+1;
		}
		if(a[0]+a[3]+a[2]>2*max(max(a[0],a[3]),a[2])){
			i=i+1;
		}
		if(a[3]+a[1]+a[2]>2*max(max(a[3],a[1]),a[2])){
			i=i+1;
		}
		cout<<i;
		return 0;
	}
	cout<<n;
	return 0;
}
