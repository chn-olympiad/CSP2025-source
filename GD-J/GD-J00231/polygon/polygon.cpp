#include<bits/stdc++.h>
using namespace std;
int a[5005],n,ma=0,zong;
int find(int m){
	m=m-1;
	
	return 0; 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[ma]){
			ma=i;
		}
	}
	if(n<3){
		cout<<"0";
		return 0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>2*a[ma]){
			cout<<"1";
		}else{
			cout<<"0";
		}
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]>=a[j+1]){
				int m=a[j+1];
				a[j+1]=a[j];
				a[j]=a[j+1];
			}
		}
	}
	for(int i=3;i<=n;i++){
		find(i);
	}
	
	cout<<zong;
	return 0;
}
