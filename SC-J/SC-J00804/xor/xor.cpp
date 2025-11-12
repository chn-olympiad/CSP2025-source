#include<bits/stdc++.h>
using namespace std;
int n,k,kk,c=0,a[500100],l[100000000],r[100000000];
int main()
{
	/*if(freopen("xor1.in","r",stdin)==NULL)
	{
		perror("重定向错误");
		return 1;
	}
	if(freopen("xor1.out","w",stdout)==NULL)
	{
		perror("重定向错误");
		return 1;
	}
	freopen("xor1.in","r",stdin);
	freopen("xor1.out","w",stdout);*/
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			kk=a[i];
			for(int o=i+1;o<=j;o++)
			{
				kk=kk^a[o];
			}
			if(kk==k)
			{
				l[c]=i,r[c]=j;
				c++; 
			}
		}
	}
	printf("%d",c);
	/*for(int i=0;i<c;i++)
	{
		printf("%d %d\n",l[i]+1,r[i]+1);
	}*/
}