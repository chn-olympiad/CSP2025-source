#include<bits/stdc++.h>
using namespace std;
long long a[600];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(max(a[0],max(a[1],a[2]))*2<a[0]+a[1]+a[2]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
