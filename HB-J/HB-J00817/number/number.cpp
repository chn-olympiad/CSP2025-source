#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int a=str.length(),nu=0;
	long long li[a]={0};
	for (int i=0;i<a;i++)
	{

		if (str[i]>=48&&str[i]<=57)
		{			
			li[i]=str[i]-'0';
			if (str[i]=='0')
			{
				nu++;
			}
		}
	}
//  sort(li,li+a);
	
//	for (int i=0;i<a;i++)
//	{
//		cout<<li[i];
//	}
//	cout<<endl<<nu;
//	return 0;
	for (int i=0;i<a;i++)
	{
		int maxx=-999;
		for (int j=0;j<a;j++)	//zuidazhi
		{
			int tmp=li[j];
			maxx=max(maxx,tmp);
		}

		for (int j=0;j<a;j++)
		{
			if (maxx==li[j]&&li[j]>0)
			{
				cout<<li[j];
				li[j]=-1;
				break;
			}
		}
	}
	for (int i=0;i<nu;i++)
	{
		cout<<"0";
	}
	return 0;
}
