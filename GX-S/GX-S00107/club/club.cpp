#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	int n,x;
	int z=0;
	int h[3];
	int a,b,c;
	cin>>x;
	for(int i=0;i<x;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a>>b>>c;
			if(a>b and a>c)
			z=z+a;
			if(b>a and b>c)
			z=z+b;
			if(c>a and c>b)
			z=z+c;
		}
		h[x+1]=z;
	}
	cout<<h[1]<<endl;
	cout<<h[2]<<endl;
	cout<<h[3];
	return 0;
}
