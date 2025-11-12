#include <bits/stdc++.h>
using namespace std;
string m;
char a[1000005];
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> m;
	int x=1,l=m.size();
	for (int i=0;i<l;i++)
	{
		if (!(islower(m[i])))
		{
			a[x]=m[i];
			x++;
		}
	}
	sort(a+1,a+x+1,cmp);
	for (int i=1;i<=x;i++)
	{
		cout << a[i];
	}
	return 0;
}
