#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000010];
int I;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			I++;
			a[I] = s[i]-'0';
		}
	}
	sort(a+1, a+I+1);
	
	for(int i=I;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
