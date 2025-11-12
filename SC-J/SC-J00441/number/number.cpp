#include<bits/stdc++.h>
using namespace std;
string c;
int a[10]={0},n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	n=c.size();
	for(int i=0;i<n;i++)
	{
		if(c[i]<='9'&&c[i]>='0')
		{
			a[(c[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}