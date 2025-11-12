#include<bits/stdc++.h>
using namespace std;
int a[101],b,c,s,x,n,m,v;
bool z(int d,int g){
	return d>g;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	int t=m*n;
	sort(a+1,a+t+1,z);
	c=1;
	while(a[c]!=b){
		c++;
	}
	c--;
	x=(c/n)+1;
	v=(c%n)+1;
	if(x%2==0){
		v=n-v+1;
	}
	cout<<x<<" "<<v;
	return 0;
}
