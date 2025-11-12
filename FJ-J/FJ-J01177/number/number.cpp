#include<bits/stdc++.h>
using namespace std;
string a;
char b[1000010];
int m=1,n,s[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	a=' '+a;
	n=a.length();
	for(int i=1;i<=n;i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			b[m]=a[i];
			m++;
		}
	}
	sort(b+1,b+m+1);
	for(int i=m;i>=1;i--)
	{
		cout << b[i];
	}
	return 0;
}
