#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int MOD=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[N];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int juq=0;
	a[0]=0;
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{	
			int sum=a[i]+a[j];
			for(int k=j+1;k<=n;k++)
			{
				if(sum>a[k])
				{
					juq++;
					juq+=(i-1)*i/2;
				}
				else 
				{
					if(sum+a[i-1]<a[k]) break;
					for(int q=i-1;q>=1;q--)
					{
						if(sum+a[q]>a[k]) juq++;
						else break;
					}
				}
			}
		}
	}
	cout<<juq%MOD;
	return 0;
}
