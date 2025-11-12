#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
vector<int> a(500100);
vector<bool> b(500100);
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n-i;j++)
		{
			int sum=0;
			bool pd=true;
			for(int k=j;k<=j+i;k++)
			{
				if(b[k]) 
				{
					pd=false;
					break;
				}
				sum=sum^a[k];
			}
			if(sum==k&&pd) 
			{
				for(int k=j;k<=j+i;k++) b[k]=true;
				ans++; 
			}
		}
	}
	printf("%d",ans);
	return 0;
}
