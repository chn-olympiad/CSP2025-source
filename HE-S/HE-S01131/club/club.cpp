#include<bits/stdc++.h>
using namespace std;
int da(int x,int y, int z)
{
	if(x>y&&x>z)
	{
		return x;
	}
	if(y>x&&y>z)
	{
		return y;
	}
	if(z>x&&z>y)
	{
		return z;
	}
	else {
		return x;
	}
	
}
int a[10000],b[10000],c[10000],t,n,cnt;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			cnt+=da(a[j],b[j],c[j]);

		}
		cout<<cnt<<endl;
	}
	
	
	return 0;
 } 
