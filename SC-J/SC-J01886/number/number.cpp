#include <bits/stdc++.h>
using namespace std;
string n;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	for (int i=0;i<n.length();i++)
	{
		int x=n[i]-'0';
		if (x<=9 && x>=0)
		{
			num[x]++;
		}
	}
	bool k=0;
	for (int i=9;i>=0;i--)
	{
		if (num[i]>0)
		{
			if (i!=0)
			{
				k=1;
			}
			if (k==0&&i==0)
			{
				cout << 0;
				break;
			}
			for (int j=1;j<=num[i];j++)
			{
				cout << i;
			}
		}
	}
	return 0;
}