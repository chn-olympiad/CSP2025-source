#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],num=1,sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0)
	{
		while(num<=n)
		{
			if(a[num]%2==0)
			{
				sum++;
				num++;
			}
			else
				if(a[num]%2==1&&a[num+1]%2==1)
				{
					sum++;
					num=num+2;
				}
			else
				num++;
		}
		cout<<sum;
	}
	if(k==1)
	{
		while(num<=n)
		{
			if(a[num]%2==1)
			{
				sum++;
				num++;
			}
			else
				if(a[num]%2!=a[num+1]%2&&num+1<=n)
				{
					sum++;
					num=num+2;
				}
			else
				num++;
		}
		cout<<sum;
	}
	return 0;
}