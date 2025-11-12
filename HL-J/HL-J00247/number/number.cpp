#include <bits/stdc++.h>
using namespace std;
string n,x;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	int u=n.size();
	n=' '+n;
	for (int i=1;i<=u;i++)
	{
		if ('0'<=n[i] && n[i]<='9')
		{
			if (n[i]=='0')a[0]++;
			if (n[i]=='1')a[1]++;
			if (n[i]=='2')a[2]++;
			if (n[i]=='3')a[3]++;
			if (n[i]=='4')a[4]++;
			if (n[i]=='5')a[5]++;
			if (n[i]=='6')a[6]++;
			if (n[i]=='7')a[7]++;
			if (n[i]=='8')a[8]++;
			if (n[i]=='9')a[9]++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		while (a[i]>0)
		{
			if (i==9)
			{
				x=x+'9';
				a[i]--;
			}
			if (i==8)
			{
				x=x+'8';
				a[i]--;
			}
			if (i==7)
			{
				x=x+'7';
				a[i]--;
			}
			if (i==6)
			{
				x=x+'6';
				a[i]--;
			}
			if (i==5)
			{
				x=x+'5';
				a[i]--;
			}
			if (i==4)
			{
				x=x+'4';
				a[i]--;
			}
			if (i==3)
			{
				x=x+'3';
				a[i]--;
			}
			if (i==2)
			{
				x=x+'2';
				a[i]--;
			}
			if (i==1)
			{
				x=x+'1';
				a[i]--;
			}
			if (i==0)
			{
				x=x+'0';
				a[i]--;
			}
		}
	}
	cout << x;
	return 0;
}
