#include<bits/stdc++.h>
using namespace std;
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int x=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==x)
			x=i+1;
	}
	int c,r;
	if(x%n==0)
		c=(x-1)/n+1;
	else
		c=x/n+1;
	r=x%n;
	if(r==0)
		r+=n;
	if(c%2==0)
		r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}
