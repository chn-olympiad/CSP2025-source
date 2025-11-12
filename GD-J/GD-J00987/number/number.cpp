#include<bits/stdc++.h>
using namespace std;	
int c[1100]={0};
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen	("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<int(a.size());i++)
	{
		char q;
		q=a[i];
		c[q-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(c[i]>0)
		{
			cout<<i;
			c[i]--;
		}
	}
	return 0;
}
