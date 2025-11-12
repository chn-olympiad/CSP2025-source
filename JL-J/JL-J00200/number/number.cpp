#include<bits/stdc++.h>
using namespace std;
#define int long long
string a;
int b,c[1000010],d;

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	b=a.size();	
	d=1;
	for(int i=0;i<b;i++)
	{
		if(a[i]<65)
		{
			c[d]=a[i]-48;
			d++;
		}
	}
	sort(c+1,c+d+1);
	for(int i=d;i>1;i--)
	{
		cout<<c[i];
	}
	return 0;
}
