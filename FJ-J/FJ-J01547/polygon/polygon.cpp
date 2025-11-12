#include<bits/stdc++.h>
using namespace std;
int n,a[100000],b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==3){
		if(a[0]+a[1]>a[2]){
			cout<<1;
			return 0;
		}
	}
	return 0;
}
