#include<iostream>
using namespace std;
long long a[500005],b[500005],c[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((b[j+i-1]^b[j-1])==k)
			{
				bool f=true;
				for(int k1=j;k1<=j+i-1;k1++)
				{
					if(c[k1]==1)
					{
						f=false;
						break;
					}
				}
				if(f==true)
				{
//					cout<<j<<" "<<j+i-1<<endl; 
					ans++;
					for(int k1=j;k1<=j+i-1;k1++)
					{
						c[k1]=1;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
