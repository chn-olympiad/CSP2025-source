#include<bits/stdc++.h>
using namespace std;
int n,m,s,o;
int a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+2;j<n;j++)
		{
			for(int q=i;q<=j;q++)
			{
				o+=a[i];
				if(a[i]>m) m=a[i];
			}
			if(o>=2*m)
			    s++;
		}
	}
	cout<<s;
	return 0;
}
