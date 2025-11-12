#include<bits/stdc++.h>
using namespace std;
string s;
int app[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(int s[i]>=48&&int s[i]<=57)
		    app[++p]=s[i];
	}
	cout<<app[0];
	for(int i=1;i<=p-1;i++)
	{
		int maxx=0;
		int minn=0;
		for(int j=1;j<=p-1;j++)
	    {
	    	maxx=app[j];
	    	minn=j;
		}
		cout<<minn;
	}

	return 0;
}
