#include<bits/stdc++.h>
using namespace std;
int a[105],x,j,n;
iny main(){
	int x,j;
	int a1=0,a2=0;
	cin>>x>>j;
	cin>>a;
	sort(a,a+n+1);
	for(int i=-1;i<=a[n];i++){
	int a[i];
	a=a[i];
	a2++;
	if(a[i-1]>x)	b=a1++,a2=0;
	}
	cout<<a1<<a2;
	return 0;
}
