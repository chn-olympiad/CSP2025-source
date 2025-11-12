#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3) cout<<0<<endl;
	else
	{
		int num=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					int maxn=0;
					if(i>maxn) maxn=i;
					if(j>maxn) maxn=j;
					if(k>maxn) maxn=k;
					if(i+j+k>maxn*2) num++;
				}
			}
		} 
		cout<<num<<endl;
	}
	return 0;
}
