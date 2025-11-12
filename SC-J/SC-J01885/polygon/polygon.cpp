#include <bits/stdc++.h> 
using namespace std;

const int q=1e6+5;
long long n,a[q];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==3){
		if(a[1]+a[0]>a[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		n-=2;
		cout<<(1+n)*n/2;
	}
	return 0;
}