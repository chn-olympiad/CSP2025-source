#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string b;
	int a[10]={0},fl=1;
	cin>>b;
	for(int i=0;i<b.size();i++)
	{
		if(b[i]-'0'>=0&&b[i]-'0'<=9)
		a[b[i]-'0']++;
	}
	for(int i=9;i>=1;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			fl=0;
			cout<<i;
		}
	}
	if(fl==0)
	for(int j=1;j<=a[0];j++)
		{
			cout<<0;
		}
		else cout<<0;
		return 0;
}
