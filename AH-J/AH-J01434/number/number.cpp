#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","R",stdin);
	freopen("number.out","W",stdout);
	string s;
	cin>>s;
	int n[s.size()],j=0,x;
	for(int i=0;i<int(s.size());i++)
	{
		if(int(s[i])-48<=9&&int(s[i])-48>=0)
		{
			n[j]=int(s[i])-48;
			x=j;
			while(n[x]>n[x-1])
			{
				swap(n[x-1],n[x]);
				x=x-1;
			}
			j++;
		}
	}
	for(int i=0;i<j;i++)
	{
		cout<<n[i];
	}
	return 0;
}
