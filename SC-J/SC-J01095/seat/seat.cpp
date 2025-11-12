#include<bits/stdc++.h.>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int l,w;
	int a,b,c,s=1;
	cin>>l>>w>>a;
	for(int i=2;i<=l*w;i++)
	{
		cin>>b;
		if(b>a)    s++;
	}
	a=ceil(s*1.0/l);
	c=(a-1)*l;
	if(a%2==1)    b=s-c;
	else    b=(l+1)-(s-c);
	cout<<a<<' '<<b;
	return 0;
}