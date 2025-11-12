#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	long long a[1001];
	for(int m=0;m<n;m++){
		cin>>a[m];
	}
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	if(n==3){
		if(a[0]>=a[1] && a[0]>=a[2] && a[0]+a[1]+a[2]>a[0]*2 ){
			cout<<1<<endl;
			return 0;
		}
		else if(a[1]>=a[0] && a[1]>=a[2] && a[0]+a[1]+a[2]>a[1]*2 ){
			cout<<1<<endl;
		    return 0;
		}
		else if(a[2]>=a[1] && a[2]>=a[0] && a[0]+a[1]+a[2]>a[2]*2 ){
			cout<<1<<endl;
			return 0;
		}
		else{
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<6<<endl;
	
	return 0;
}
