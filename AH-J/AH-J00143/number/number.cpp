#include<bits/stdc++.h>
using namespace std;
string a;
int s[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			s[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(s[i]!=0)
		{
			cout<<i;
			s[i]--;
		}
	}
	return 0;
}
