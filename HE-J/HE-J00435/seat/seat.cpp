#include<bits/stdc++.h> 
using namespace std;
int m,n,a,b,c,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++)
	{
		cin>>b;
		if(b>a) c++;
	}
	d=(c+1)%(2*n);
	if(d>n) d=2*n+1-d;
	cout<<(c/n+1)<<' '<<d;
	return 0;
}
