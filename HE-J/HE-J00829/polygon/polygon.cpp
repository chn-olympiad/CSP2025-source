#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s,w,b,c;
int main()
{
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		if(s+a[i]>max(a[i],s))
		{
			w=(s+a[i])%998;
			b=(s+a[i])%244;
			c=(s+a[i])%353;
			cout<<w<<b<<c;
		}
	}
	
}
