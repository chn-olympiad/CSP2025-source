#include<iostream>
#include<string>
using namespace std;
int t[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;a[i]!='\0';i++)
	{
		if('0'<=a[i]<='9')
		t[a[i]-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=t[i];j++)cout<<i;
	}
	return 0; 
}
