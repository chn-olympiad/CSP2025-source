#include<bits/stdc++.h>
using namespace std;
int a[1005000];
int he(int x,int y)
{
	int h = a[x];
	for(int i=x+1;i<=y;i++)
	{
		h=h^a[i];
	}
    return h;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[1005000],re=0;
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			if(he(i,j)==k)
			{
				re++;
				i=j+1;
				continue;
			}
		}	
	}
	cout<<re;
	return 0;
}