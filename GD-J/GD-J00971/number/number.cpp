#include<bits/stdc++.h>
using namespace std;
int n[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin >> s;
	int b=0;
	int a=s.size();
	for(int i=0;i<a;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			b=s[i]-'0';
			n[b]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<n[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
