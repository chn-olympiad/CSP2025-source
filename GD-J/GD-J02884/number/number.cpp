#include<bits/stdc++.h>
using namespace std;

int num[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(char c:s)
	{
		if(c>='0' && c<='9')
		{
			num[(c-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(num[i]--)
		{
			cout<<i;
		}
	}
	
	return 0;
}
