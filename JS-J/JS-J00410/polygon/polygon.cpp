#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	if(n<=20)
	{
		long long fangan=0;
		for(int i=0;i<pow(2,n);i++)
		{
			int o=i;
			int m=0,h=0,k=0;
			long long sum=0;
			while(o>0)
			{
				if(o%2==1)
				{
					h++;
					sum=sum+a[k];
					if(a[k]>m)
					{
						m=a[k];
					}
					k++;
					o/=2;
				}	
				else
				{
					k++;
					o/=2;
				}
			}
			if(sum>2*m)
			{
				fangan++;
				fangan%=998244353;
			}
		}
		cout << fangan;
	}
	else
	{
		int f=0;
		for(int i=3;i<=n;i++)
		{
			f++;
		}
		cout << f;
	}
	return 0;
}
