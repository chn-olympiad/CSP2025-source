#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],p,x,y,now=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-2;i>=0;i--){
		now+=a[i];
	}
	if(now<=2*a[n-1]){
		cout<<0;
		return 0;
	}
	
}   