#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const long long mod=998244353;
int s[505],c[505];
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		s[i]=c-'0';
		a[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	int ans=0;
	do
	{
		int k=0,res=0;
		for(int t=1;t<=n;t++)
		{
//			printf("%d ",a[t]);
			int i=a[t];
			if(k>=c[i])
			{
				k++;
			}
			else if(!s[t])
			{
//				printf("%d:",i);
				k++;
			}
			else
			{
				res++;
			}
		}
		ans+=(res>=m);
//		printf("%d\n",res);
	}
	while(next_permutation(a+1,a+n+1));
	printf("%d",ans);
	return 0;
}
/*
3 1
001
3 3 1
*/
