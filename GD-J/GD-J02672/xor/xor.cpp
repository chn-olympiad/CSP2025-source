#include <bits/stdc++.h> 
using namespace std;
const int MAX=5e5+6;
int n,k,cnt=0;
int x,wz;
int a[MAX];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if (a[i]==k)
		{
			cnt++;
			wz=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (wz<i || wz>j)
			{
				x=a[i];
				for(int k=i+1;k<j;k++)
				{
					x=x||a[k];
				}
				if ((x||a[j]==k)&&a[i]!=0&&a[j]!=0)
				{
					cnt++;
				}
			}
			
		}
	}
	cout<<cnt<<endl;
	return 0;
}

