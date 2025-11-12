#include<bits/stdc++.h>
using namespace std;
string a,s;
int t[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=a.size();
	for(int i=0;i<l;i++)
	{
		int x=a[i]-'0';
		if(x>=0&&x<=9)
			t[x]++;
	}
	for(int i=9;i>=0;i--)
	{
		while(t[i])
		{
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}