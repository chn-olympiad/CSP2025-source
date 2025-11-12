#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b[1000010],ans=0;
	cin>>a;
	for (int i=0;i<a.size();i++)
	{
		if ('0'<=a[i] && a[i]<='9')
		{
			b[ans]=a[i]-'0';
			ans++;
		}
	}
	sort(b,b+ans);
	for (int i=ans-1;i>=0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
