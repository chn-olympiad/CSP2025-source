#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b[1000];
	string a;
	cin >> a;
	int c = a.size();
	for(int i = 0 ;i < c;i++)
	{
		if(a[i]==0||a[i]==1||a[i]==2||a[i]==3||a[i]==4||a[i]==5||a[i]==6||a[i]==7||a[i]==8||a[i]==9)
		{
			b[i]++;
		}
	}
	sort(b,b[c]);
	for(int i = c;i >= 0; i--)
	{
		cout<<b[i];
	}
	return 0;
}
