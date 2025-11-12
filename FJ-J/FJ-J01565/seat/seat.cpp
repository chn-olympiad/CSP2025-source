#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>n>>m;
	int a[10000];
	for(int i=1;i<=m*n;i++)cin>>a[i];
	int g=a[1];
	sort(a+1,a+1+n*m);
	int c=1,r=1;
	for(int i=m*n;i>=1;i--){
		if(g==a[i])break;
		else if(c%2==0)r--;
			 else r++;
		if(r>n){
			r--;
			c++;
		}
		if(r<1){
			r=1;
			c++;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}