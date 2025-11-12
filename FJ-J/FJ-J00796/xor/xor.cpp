#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	bool f=1;
	int s=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(!(a[i]==0||a[i]==1))
			f=0;
		if(a[i]==1)
			s+=1; 
	}
	if(f==1)
	{
		if(k==0)
		{
			printf("%d",s/2);
			return 0;
		}
		if(k==1)
		{
			printf("%d",s);
			return 0;
		}
	}
	return 0;
}
