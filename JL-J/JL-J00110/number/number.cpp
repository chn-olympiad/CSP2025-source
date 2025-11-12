#include<bits/stdc++.h>
using namespace std;
string a;
int b[100000],e[100000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int c,d=0,f=-1,g;
	cin>>a;
	for(int i=0;i<100000;i++)
	{
		b[i]=0;
	}
	for(int i=0;i<100000;i++)
	{
		c=a[i];
		if(c<=57&&c>=48)
		{
			b[d]+=a[i]-48;
			d++;
		}
	}
	for(int i=0;i<d;i++)
	{
		for(int q=0;q<d;q++)
		{
			if(b[q]>f)
			{
				f=b[q];
				g=q;
			}
		}
		cout<<f;
		b[g]=-2;
		f=-1;
	}
	return 0;
}
