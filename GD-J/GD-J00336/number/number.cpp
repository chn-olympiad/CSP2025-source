#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=49&&s[i]<=57)
		{
			cnt++;
		}
	}
	int a[cnt];
	int num=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i]-'0';
		}
	}
	//for(int i=0;i<cnt;i++)
	//{
	//	cout<<a[i]<<' ';
	//}
	for(int j=0;j<cnt;j++)
	{
		for(int i=0;i<cnt;i++)
		{
			if(a[i+1]>a[i])
			{
				int temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
	for(int i=0;i<cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
