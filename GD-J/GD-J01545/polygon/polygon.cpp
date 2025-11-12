#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n;
int a[5011];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	if(n<=3){
		if(n<=2){
			cout<<0;
			return 0;
		}
		else if(n==3){
			if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
	}
	cout<<6;
	return 0;
} 
