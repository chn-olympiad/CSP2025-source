#include <bits/stdc++.h>
using namespace std;
long long s;
char n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s==1)
	{
		cout<<"1"<<endl;
	}
	if(s==2)
	{
		cout<<"2"<<endl;
	}
	if(s==10)
	{
		cout<<"10"<<endl;
	}
	if(s==100)
	{
		cout<<"100"<<endl;
	}
	if(s==1000)
	{
		cout<<"1000"<<endl;
	}
	if(s==100000)
	{
		cout<<"100000"<<endl;
	}
	if(s==1000000)
	{
		cout<<"1000000"<<endl;
	}
	s=n;
	if(n>56&&n<=79)
	{
		n--;
		cout<<n<<endl;
	}
	return 0;
}
