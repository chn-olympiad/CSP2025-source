#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int j=sizeof(s);
	while(j+1)
	{
		if(s[j]>='0'&&s[j]<='9')
		{
			a[s[j]-'0']++;
		}
		j--;
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]!=0)
		{
			for(int l=1;l<=a[i];l++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
