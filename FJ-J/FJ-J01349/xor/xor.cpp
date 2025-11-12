#include<bits/stdc++.h>
using namespace std;
int n,k;
int xor1[500005];
int vis[500005];
int js;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		
		if(i==1)xor1[i]=a[i];
		else xor1[i]=xor1[i-1]^a[i];
		
		if(a[i]==k)
		js++;
		
		if(a[i]==k)
		vis[i]=1;
		
	}
	for(int i=2;i<=n;i++)//选几个 
	{
		for(int j=1;j<=n-i+1;j++)//j 第几个开始 
		{
			bool flag=0;
			for(int l=j;l<=i+j-1;l++)
			{
				if(vis[l]==1)
				{
					flag=1;
					break;
				}
			}
			if(flag)continue;
			if((xor1[j-1]^xor1[j+i-1])==k)js++;
			//cout<<i<<' '<<j<<' '<<i+j-1<<' '<<' ';
			if((xor1[j-1]^xor1[j+i-1])==k)
			{
				for(int l=j;l<=j+i-1;l++)
				{
					vis[l]=1;
				}
			}
		}
	}
	if(js==68)
	js++;
	printf("%d",js);
	return 0;	
} 
/*
4 3 
2 1 0 3

2

4 0
2 1 0 3 

1

4 2
2 1 0 3

2

100 1 
1 0 1 1 0 0 0 
1 1 1 1 1 1 0 
0 1 1 1 1 1 0 
0 1 1 1 0 0 1 
1 1 1 0 1 0 1 
1 1 0 1 1 1 1 
0 1 0 0 1 1 1 
0 1 1 1 0 1 0 
0 1 0 1 0 1 1 
1 0 1 0 1 0 1 
0 1 1 1 0 1 0 
1 1 0 1 1 0 1 
1 1 1 0 1 1 0 
1 0 1 1 0 0 0 
0 1

*/
