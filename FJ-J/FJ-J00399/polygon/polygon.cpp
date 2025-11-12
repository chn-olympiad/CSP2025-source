#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,b,c,s;
	cin>>n;
	cin>>a>>b>>c;
	s=max(a,max(b,c));
	if(a+b+c>s*2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}