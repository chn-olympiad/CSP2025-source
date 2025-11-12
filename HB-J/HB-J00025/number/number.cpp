#include <bits/stdc++.h>
using namespace std;
string a;
int book[15];
int main()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin >> a;
	for (long unsigned int i=0;i<a.size();i++)
	{
		if ('0'<=a[i]&&a[i]<='9') book[a[i]-'0']++;
	}
	for (int i=9;i>=0;i--)
	{
		for (int j=1;j<=book[i];j++) cout << i;
	}
	return 0;
}
