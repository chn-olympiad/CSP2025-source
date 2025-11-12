#include<bits/stdc++.h>
using namespace std;
char s;
long long a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s)
	{
		if(s>='0'&&s<='9')
		{
			a[s-'0']++;
		}
	} 
	for(int i=9;i>=0;i--)
	{
		if(a[i]!=0)
		{
			for(int j=1;j<=a[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
