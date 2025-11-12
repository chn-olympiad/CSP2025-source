#include<bits/stdc++.h>
using namespace std;
int n,a[5009];
int maxx=0;
long long b[362880];



int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	sort(a+1,a+1+n);
//	long long s=1;
//	for(int i=2;i<n;i++){
//		s*=i;
//	}
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
	
	
	return 0;
} 