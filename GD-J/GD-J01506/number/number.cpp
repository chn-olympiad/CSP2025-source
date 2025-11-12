#include<bits/stdc++.h>
using namespace std;
string mys;
int myt[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>mys;
	bool flag=0;
	int len=mys.size();
	for(int i=0;i<len;i++)
	{
		if('0'<=mys[i]&&mys[i]<='9')
		{
			myt[mys[i]-'0']++;
			if((mys[i]-'0')!=0)
			{
				flag=1;
			}
		}
	}
	if(flag==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		int c=myt[i];
		for(int j=1;j<=c;j++)
		{
			cout<<i;
		}
	}
	return 0;
 } 
