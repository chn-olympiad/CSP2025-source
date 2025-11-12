#include<bits/stdc++.h>
using namespace std;
char s;
int a[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s)
	{
		if(s>='0'&&s<='9')
		    a[s-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i])
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}