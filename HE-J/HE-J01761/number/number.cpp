#include<iostream>
#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int num[11];
	cin>>a;
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<=a.length();j++)
		{
			if(a[j]==48+i)cout<<a[j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
