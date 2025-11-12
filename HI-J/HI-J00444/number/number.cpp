#include<bits/stdc++.h> 
using namespace std;
string s;
int a[10000009];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num = 0;
	cin>>s;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i] >= 'a'&&s[i] <= 'z')
		{
			num++;
		}
		if(s[i] >= '0'&&s[i]<='9')
		{
			a[i]+=s[i];
			if(a[i] == 48)
			{
				a[i] = 0;
			}
			else if(a[i] == 49)
			{
				a[i] = 1;
			}
			else if(a[i] == 50)
			{
				a[i] = 2;
			}
			else if(a[i] == 51)
			{
				a[i] = 3;
			}
			else if(a[i] == 52)
			{
				a[i] = 4;
			}
			else if(a[i] == 53)
			{
				a[i] = 5;
			}
			else if(a[i] == 54)
			{
				a[i] = 6;
			}
			else if(a[i] == 55)
			{
				a[i] = 7;
			}
			else if(a[i] == 56)
			{
				a[i] = 8;
			}
			else if(a[i] == 57)
			{
				a[i] = 9;
			}
		}
	}
	sort(a,a+s.size());
	for(int i = s.size()-1;i>=num;i--)
	{
		cout<<a[i];
	}
	
	return 0;
}
