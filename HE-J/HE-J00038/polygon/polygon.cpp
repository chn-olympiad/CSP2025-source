#include<bits/stdc++.h>
using namespace std;
int b[3];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	int sum=0;
	for(int i=0;i<3;i++)
	{
		cin>>b[i];
		sum+=b[i];
	}
	int maxl=max(b[0],b[1]);
	maxl=max(maxl,b[2]);
	if(maxl*2<sum)
	{
		cout<<1;
	}else
	{
		cout<<0;
	}
	return 0;
}
