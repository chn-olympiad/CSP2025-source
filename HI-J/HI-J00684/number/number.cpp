#include<bits/stdc++.h>
using namespace std;
string s;
int a[100000];
int sum=0;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int d=-1;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=0;i<=100;i++)
	{
		if(a[i]>d)
		{
			d=a[i];
		}
		cout<<d;
	}
	return 0;
}
