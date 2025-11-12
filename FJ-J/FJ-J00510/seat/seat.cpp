#include<bits/stdc++.h>
using namespace std;
int a,b,c[111111],d,e[1111][1111],f;
string s;
int main()
{
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++)
	{
		cin>>c[i];
		d=c[1];
	}
	sort(c+1,c+a*b+1);
	for(int i=a;i>=1;i--)
	{
		if(i%2==0)
		{
			for(int j=1;j<=b;j++)
		    {
		    	f++;
		    	e[j][i]=c[f];
		    	if(c[f]==d)
		    	{
		    		cout<<i<<" "<<j;
		    		return 0;
		    	}
	     	}
		}
		if(i%2==1)
		{
			for(int j=b;j>=1;j--)
		    {
		    	f++;
		    	e[j][i]=c[f];
		    	if(c[f]==d)
		    	{
		    		cout<<i<<" "<<j;
		    		return 0;
		    	}
	     	}
		}
	}
	return 0;
} 
