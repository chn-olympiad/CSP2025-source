#include<bits/stdc++.h>
using namespace std;
int a[10005],cnt=0,b[10005];
int n,s=0;
int k;
void meiju(int x)
{
	for(int i=x;i<n;i++)
	{
		for(int j=x+1;j<=i;j++)
		{
			if(b[j]==0)
			{
				cnt=cnt^a[j];
			}
			else
			{
				break;
			}
		}
		if(cnt==(k^0))
		{
			s++;
			for(int j=x;j<=i;j++)
			{
				b[j]=1;
			}
		}
	}
	if(x!=n)
		meiju(x+1);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	meiju(0);
	cout<<s;
	return 0;
}
