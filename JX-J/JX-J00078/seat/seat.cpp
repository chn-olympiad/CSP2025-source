#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long x,y,a[10005]={};
	cin>>x>>y;
	for(int i=0;i<x*y;i++){
		cin>>a[i];
	}
	int n=a[0],ans=0,z=x*y;
	sort(a,a+z,cmp);
	for(int i=0;i<x*y;i++){
		if(a[i]==n){
			ans=i;
			break;
		}
	}
	long long j=ans/x+1,k=0;
	if(j%2==0){
		k=x-ans%x;
	}else{
		k=ans%x+1;
	}
	cout<<j<<' '<<k;
	return 0;
}
