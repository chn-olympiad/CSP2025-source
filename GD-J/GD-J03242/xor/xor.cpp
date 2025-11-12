#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10,INF=0x3f3f3f3f;
int n,k,minn=INF,tong[5];
int a[N],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		minn=min(minn,a[i]);
		if(a[i]==0)  tong[0]++;
		else if(a[i]==1)  tong[1]++;
	}  
	if(minn==1)
	{
		printf("%d",n/2);
		return 0;
	}
	if(minn!=1)
	{
		if(k==1 && minn==0)
		{
			printf("%d",tong[1]);
		}
		else if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==a[i+1] && (a[i]!=0 || a[i+1]!=0))  ans++,i++;
			}
			printf("%d",ans+tong[0]);
		}
	}
	return 0;
}
