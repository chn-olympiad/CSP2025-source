#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
int c[100000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m;
	cin>>m;
	while(m--)
	{
		int n;
		cin>>n; 
		for(int i=1; i<=n; i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		int s=0;
		for(int i=1; i<=n; i++)
		{
			s+=a[i];
		}
		cout<<s<<endl;
		for(int i=1; i<=n; i++)
		{
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}
	}
	return 0;
} 
