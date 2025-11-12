#include<iostream>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
	ifstream cin("number.in");
	ofstream cout("number.out");
	string s;
	cin>>s;
	int a[1000]={0};
	int len=s.size();
	int j=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+0,a+0+j);
	for(int i=j-1;i>=0;i--)
	{
		cout<<a[i];
		
			if(a[j-1]==0)
			{
				break;
			}
			
	}
	return 0;
}
