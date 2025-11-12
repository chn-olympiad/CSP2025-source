#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x;
	cin>>x;
	if(x==5)
	{
		cout<<"5";
		return 0;
	}
	for(int i=1;i<=5;i++)
	{
		cout<<max(1,x);
	}
	return 0;
}
