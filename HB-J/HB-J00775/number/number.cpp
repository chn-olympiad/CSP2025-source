#include<bits/stdc++.h>
using namespace std;
string s;
int l,is=10;
int main()
{
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=57;i>=48;i--)
	{
		is--;
		for(int j=0;j<l;j++)
		{
			if(s[j]-0==i)
			{
				cout<<is;
			}
		}
	}
	return 0;
}
