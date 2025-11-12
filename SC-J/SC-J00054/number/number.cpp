#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=11;
int a[N];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]!=0) 
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}