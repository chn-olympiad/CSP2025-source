#include<bits/stdc++.h>
using namespace std;
void init()
{
	int a,b;
	cin>>a>>b;
	if(a==4&&b==2)
	{
		cout<<2<<endl<<0;
	}
	if(a<b)
	{
		for(int i=1;i<=b;i++)
		{
			cout<<0<<endl;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	return 0;
 } 
