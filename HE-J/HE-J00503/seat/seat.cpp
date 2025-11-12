#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,x,y,c;
	int a[100001];
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+n*m+1);
	for (int i=n*m;i>=0;i--){
		if (a[i]==b){
			c=m*n-i+1;
		}
	}
	x=c/n;
	cout<<x<<" ";
	if (x%0==1){
		if (c%n==0){
			y=n;
		}
		else{
			y=c%n;
		}
	}
	else{
		if (c%n==0){
			y=n;
		}
		else{
			y=n-(c%n)+1;
		}
	}
	cout<<y;
	return 0;
}
