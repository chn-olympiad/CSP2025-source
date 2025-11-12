#include <bits/stdc++.h>
using namespace std;
string s;
int b[10];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	
	int i;
	cin>>s;
	for(i=0; i<s.size(); i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			int a=s[i]-'0';
			b[a]++;
		}
	}
	for(i=9; i>=0; i--)
	{
		while(b[i]!=0)
		{
			cout<<i;
			b[i]--;
		}
	}
	return 0;
}
