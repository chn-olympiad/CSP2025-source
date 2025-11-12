#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long l,b[11]={0};
	cin>>a;
	l=a.size();
	for(int i=0;l-1>=i;i++)
	{
		if('0'<=a[i]&&a[i]<='9')
		{
			b[a[i]-'0']++;
		}
	}
	for(int i=9;0<=i;i--)
	{
		while(b[i]>0)
		{
			cout<<i;
			b[i]--;
		}
	}
	return 0;
}
