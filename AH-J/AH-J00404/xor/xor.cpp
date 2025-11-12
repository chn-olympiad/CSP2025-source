#include<bits/stdc++.h>
using namespace std;

int n,k,a[500010],s,u;

int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		u=0;
		for(int j=i;j<=n;j++)
		{
			u=u^a[j];
			if(u==k)
			{
				s++;
				i=j+1;
				u=0;
			}
		}
	}
	cout<<s;		
	return 0;
}
