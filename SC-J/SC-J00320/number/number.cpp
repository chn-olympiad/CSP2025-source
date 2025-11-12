#include<iostream>
using namespace std;
string a;
int a_int[100000000],a_int_i;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if('0'<=a[i]&&a[i]<='9')
		{
			a_int[a_int_i]=a[i]-'0';
			a_int_i++;
		}
	}
	for(int i=0;i<a_int_i;i++)
	{
		for(int j=i+1;j<a_int_i;j++)
		{
			if(a_int[i]<a_int[j])
			{
				int n=a_int[i];
				a_int[i]=a_int[j];
				a_int[j]=n;
			}
		}
	}
	for(int i=0;i<a_int_i;i++)cout<<a_int[i];
	return 0;
} 