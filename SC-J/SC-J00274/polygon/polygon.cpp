#include<bits/stdc++.h>
using namespace std;
int n,s[5005],m;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
    m=n;
	while(n--)
	{
		cin>>s[n];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)if(s[i]<s[i+1])
		{
			n=s[i];
			s[i]=s[i+1];
			s[i+1]=n;
		}
	}
	cout<<s[0];
	return 0;
}