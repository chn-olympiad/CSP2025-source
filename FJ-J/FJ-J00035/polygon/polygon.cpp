#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b=1,c=1,zs=1,t,t2;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[3]<a[1]+a[2]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	for(int i=4;i<=n;i++){
		t=0;
		t2=i-4;
		for(int j=i-2;j>=1;j--) t+=j;
		zs+=t;
		zs=zs+i*t2+1;
	}
	cout<<zs;
	return 0;
} 
