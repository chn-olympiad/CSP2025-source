#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b,c,n,x,y;
	cin>>n;
	cin>>a>>b>>c;
	x=a+b+c;
	if(a>b and a>c)
		y=a;
	else if(b>a and b>c)
		y=b;
	else
		y=c;
	if(x>y*2)
		cout<<1<<endl;
	else
		cout<<0<<endl;
	return 0;
}
