#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,b,cnt=0,cmp=0;
struct node{
	int sum,flag;
}a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&b);
		a[i].sum=b;
		a[i].flag=0;
		if(a[i].sum==k)
		{
			ans++;
			a[i].flag=1;
		} 
	}
	for(int i=1; i<=n-1; i++)
	{
		if(a[i].flag==1)
		{
			continue;
		}
		cnt=a[i].sum;
		for(int j=i+1; j<=n; j++)
		{
			if(a[j].flag==1)
			{
				cmp=j-1;
				break;
			}
			cnt=cnt^a[j].sum;
		}
		if(cnt==k)
		{
			a[i].flag=1;
			for(int f=i+1; f<=cmp; f++)
			{
				a[f].flag=1; 
			}
			ans++;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
