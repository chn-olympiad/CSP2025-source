#include <bits/stdc++.h>
using namespace std;
int n=0,c[1000000];
string a,b;
int main()
{
    freopen("number.in","in","r");
    freopen("number.ans","out","c");
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b[n]=a[i];
			n++;
		}
	}
	for(int i=0;i<n;i++)
	{
		c[i]=b[i]-'0';
	}
	sort(c,c+n);
	for(int i=n-1;i>=0;i--)
	{
		cout<<c[i];
	}
    return 0;
}