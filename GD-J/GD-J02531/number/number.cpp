#include<iostream>
using namespace std;
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int l;
	getline(cin,s);
	l=s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int x=int(s[i]-'0');
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			a[i]--;
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
