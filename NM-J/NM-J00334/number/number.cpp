#include<bits/stdc++.h>
using namespace std;
int a[10000];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int i,j;
	cin>>s;
	int lena=s.length();
	for (i=9;i>=0;i--)
	{
		for (j=0;j<lena;j++)
			if (s[j]-'0'==i) cout<<i;
	}	
	return 0;
}	
