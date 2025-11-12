#include<bits/stdc++.h>
using namespace std;
int b[1000005],t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0; i<a.size(); i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			t++;
			b[t]=a[i]-48;
		}
	}
	sort(b+1,b+1+t);
	for(int i=t; i>=1; i--)
	{
		cout<<b[i];
	}
	return 0;
}
