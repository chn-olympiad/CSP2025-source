#include<bits/stdc++.h>
using namespace std;
int t,n;
struct edge{
	int a,b,c;
}s[100000];
int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		int k=0,a=0,b=0,c=0;
		for (int i=1;i<=n;i++)
		{
			k+=max(max(s[i].a,s[i].b),s[i].c);
			
		}
		cout<<k<<endl;
	}
}

