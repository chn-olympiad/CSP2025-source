#include<bits/stdc++.h>
using namespace std;

int a[1005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int n1,n2,n3,cnt=0;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		int l=a[0]+a[1]+a[2],mm=a[2];
		if(l>2*mm){
			cout<<1;
			return 0;
		}
		
	}
	cout<<0;
	return 0;
} 
