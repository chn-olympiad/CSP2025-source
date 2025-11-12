#include<iostream>
using namespace std;
long long n,m,sum,ans;
int main(){
	cin>>n>>m;
	for(long long u;u<=n-m;u++)
	{
		for(long long i;i<=n+m;i++)
		{
			for(long long w;w<=n/m;w++)
			{
				for(long long c;c<=n%m;c++)
				{
					for(long long j;j<=n*m;j++)
					{
						for(long long k;k<=n^m;k++)
						{	
							sum+=(u-i)*(w+c)/(j%k);
							ans-=(u/i)+(w%c)-(j*k);
							break;	
						}
						break;
					}
					break;
				}
				break;
			}
			break;
		}
		break;
	}
	cout<<ans+sum<<"\n";
	return 0;
}
