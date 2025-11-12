#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout)
	
	int a,b,c;
		cin>>a>>b>>c;
	if(a+b>c and a+c>b and b+c>a)
		cout<<"1";
	else
		cout<<"0";
	return 0;
}

