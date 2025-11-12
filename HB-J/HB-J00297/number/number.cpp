#include <bits/stdc++.h>
using namespace std;
string a;
int b[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int lena=a.size();
	for(int i=0;i<lena;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[a[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(b[i]>=1)
		{
			while(b[i]--)cout<<i;
		}
	}
	return 0;
}
