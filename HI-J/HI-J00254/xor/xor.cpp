#include<bits/stdc++.h>
using namespace std;
int n,k,a[551514],f=1; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1)
		{
			f=0;
		}
	}
	if(f==0&&n%2==0)
	{
		cout<<0;
	}
	else
	{
		cout<<1;
	}
	return 0;
}
