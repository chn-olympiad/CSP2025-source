#include <bits/stdc++.h>
using namespace std;
string a;
int f[15],n,o;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			if(a[i]!='0')
			{
				o=1;
			}
			f[int(a[i]-'0')]++;
		}
	}
	if(o==0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=f[i];j++)
		{
			cout<<i;
		}
	}
}
