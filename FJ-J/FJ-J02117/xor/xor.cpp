#include<bits/stdc++.h>
using namespace std;
int a[500050],n;
long long k,s=0;
int xx(int x,int y)
{
	if(x==y) return 0;
	else return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1) s++;
	}
	if(k==1) printf("%lld",s);
	else
	{
		s=n-s;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==1&&a[i-1]==1) 
			{
				s++;	
				i++;
			}
		}
		printf("%lld",s);
	}
	return 0;
}