#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000009];
int n[30];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	for(int i=0;i<=a.size();i++)
	{
		if(a[i]<='9'&a[i]>='0')
		{
			int x;
			x=a[i]-' ';
			n[x]++;
		}
	}
	for(int i=25;i>=16;i--)
	{
		for(int j=1;j<=n[i];j++)
		{
			cout<<i-16;
		}
	}
	cout<<"\n"; 
	return 0;
} 