#include<bits/stdc++.h>
using namespace std;
string s;
long a[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[s[i]-48]++;
		}
	}
	for(long i=10;i>=0;i--)
	{
		if(a[i]>0)
		{
			while(a[i]>0)
			{
				cout<<i;
				a[i]--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
