#include<bits/stdc++.h>

using namespace std;
string s;
int bz[100005];
int l;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		int a;
		a=int(s[i])-48;
		bz[a]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=bz[i];j++)
		{
			cout<<i;	
		} 
	}
	return 0;
} 
