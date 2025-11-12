#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","n",stdin);
	freopen("polygon.out","u",stdout);
	int a[10000005]={};
	int n,x,y,z,u,v,w;
	cin>>n;
	u=0;
	v=0;
	w=0;
	x=0;
	y=0;
	z=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int j=3;j<=n;j++)
	{
		for(int k=1;k<=j;l++)
		{
			z=z*((n-j+k)/k)
		}
		for(int l=0;l<z;l++)
		{
			for(int m=0;m<n;m++)          //选择木棍的循环没有完全做好
			{
				y=y+a[m];
				if(x<a[m])
				{
					x=a[m];
				}
			}                             //选择木棍的循环没有完全做好
			if(y>2*x)
			{
				u+=1;
			}
		}
	}
	cout<<u<<endl;
	return 0;
}
