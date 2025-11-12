#include<bits/stdc++.h>
using namespace std;
int n,a[5010],b;
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b=(n-2)*(n-2);
	if(a[1]+a[2]+a[3]<a[1]*2||a[1]+a[2]+a[3]<a[2]*2||a[1]+a[2]+a[3]<a[3]*2){
		b-=1;
	}
	cout<<b;
	return 0;
}