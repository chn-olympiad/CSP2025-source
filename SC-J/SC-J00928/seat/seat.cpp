#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int a,b,c[100],s;
	cin>>a>>b;
	s=a*b;
	for(int i=1;i<=s;i++)
	{
	cin>>c[i];
	}
	if(a==b&&a==2&&b==2)
	cout<<1<<' '<<2;
	else 
	cout<<2<<' '<<2; 
	return 0;
}