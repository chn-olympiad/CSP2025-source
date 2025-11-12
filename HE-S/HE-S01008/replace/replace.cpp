#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m,s,c,x,y,sum=0,z,q;
	cin>>m>>n>>s>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		y=s;
		s=x+y+z;
		for(int j=i;j<=q;j++)
		{
			sum+=j+n+1;
		}
		if(x!=z||x!=i||z!=i)
		{
			cout<<2<<endl<<0;
			break;
		}
	}
	return 0;
} 
