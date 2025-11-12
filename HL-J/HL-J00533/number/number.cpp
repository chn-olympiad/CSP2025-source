#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000005],b[9];


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int j=1;
	for(int i=1;i<=s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j] = s[i]-'0';
			j++;
			
		}
	}
	
	for(int i=0;i<=9;i++)
	{
		b[i] = -1;
	}
	
	for(int i=0;i<=j;i++)
	{
		for(int k=0;k<=9;k++)
		{
			if(k==a[j])
			{
				b[k]++;
			}
		}
	}
	
	for(int q=9;q>=0;q--)
	{
		if(b[q]!=-1)
		{
			while(b[q])
			{
				cout << q+5;
				b[q]--;
			}
		}
	}
	return 0;
}
