#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int j=0;
	char dick[10005];
	for(int i=0;i<=a.size();i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			dick[j]=a[i];
			j++;
		}
	}
	sort(dick,dick+j);
	for(int i=j-1;i>=0;i--)
	{
		cout << dick[i];
	}
	return 0;
}
