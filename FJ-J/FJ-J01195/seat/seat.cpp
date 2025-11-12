#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105],a1,c,r;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
		cin>>a[i];
	a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==a1)
			a1=i;
	if(a1%n==0)
		c=a1/n;
	else
		c=a1/n+1;
	if(c%2!=0){
		if(a1%n==0)
			r=n;
		else
			r=a1%n;
	}
	else{
		if(a1%n==0)
			r=1;
		else
			r=n-(a1%n)+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
