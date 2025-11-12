#include<bits/stdc++.h>
using namespace std;
string t,s;
int n,cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cnt=1;
	cin>>s;
	n=s.size();
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			if(s[j]==i+'0')
			{
				t+=s[j];
				cnt++;
			}
		}
	}
	cout<<t;
	return 0;
}
