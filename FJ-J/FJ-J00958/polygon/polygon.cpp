#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0,a[5005],m,k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	m=max(a[1],a[2]);
	k=max(a[3],a[2]);
	if(n==3){
		if(2*max(m,k)<a[1]+a[2]+a[3]){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		return 0;
	}
	if(n<3){
		cout<<"0";
		return 0;
	}
	return 0;
}
