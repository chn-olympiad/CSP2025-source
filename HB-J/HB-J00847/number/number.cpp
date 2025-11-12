#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long g=0;
	string s;
	char c[1000001];
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			c[g]=s[i];
			g++;
		}
	}
	sort(c,c+g);
	for(int i=g-1;i>=0;i--)
	{
		cout<<c[i];
	}
	return 0;
}
