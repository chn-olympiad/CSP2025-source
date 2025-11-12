#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500002];
bool b[500002];
long long yhh,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<"i="<<i;
//		if(b[i]==true)
//		{
//			continue;
//		}
//		else
//		{
			yhh=a[i];
			for(int j=i;j<=n+1;j++)
			{
//				if(b[j]==true)
//				{
//					break;
//				}
//				cout<<"j="<<j;
				if(yhh==k)
				{
					ans++;
					i=j;
//					cout<<"guole";
//					for(int k=i;k<=j;k++)
//					{
//						b[k]=true;
//					}
					break;
				}
				else if(j<=n)
				{
					if(j!=i)
					yhh=yhh^a[j];
//					cout<<"yhh="<<yhh;
				}
			}
//			cout<<endl;
//		}
	}
	printf("%lld",ans);
	return 0;
}
