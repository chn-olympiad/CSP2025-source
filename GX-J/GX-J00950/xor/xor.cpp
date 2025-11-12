#include<bits/stdc++.h>
using namespace std;
bool p[100010],q=false;
unsigned long long a[100010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	unsigned long long n,k,x;
	int sum=0;
	cin>>n>>k;
	for(unsigned long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(unsigned long long i=1;i<=n;i++)
	{
		for(unsigned long long j=i;j<=n;j++)
		{
			x=a[i];
			//cout<<"i:"<<i<<" j:"<<j<<endl;
			for(unsigned long long k=i+1;k<=j;k++)
			{
				x^=a[k];
				//cout<<"a["<<k<<"]:"<<a[k]<<endl;
				//cout<<"x:"<<x<<endl;
				if(p[k])
				{
					q=true;
					break;
				}
			}
			if(x==k&&q==false)
			{
				sum++;
				//cout<<"sum plus,sum:"<<sum<<endl;
				for(unsigned long long k=i;k<=j;k++)
				{
					p[k]=true;
				//	cout<<"p["<<k<<"]"<<p[k]<<endl;
				}
				if(j<n)
				{
					i=j+1;
				}
			}
			q=false;
		}
	}
	cout<<sum;
	return 0;
}
