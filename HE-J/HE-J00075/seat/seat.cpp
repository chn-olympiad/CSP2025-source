#include<bits/stdc++.h>
using namespace std;
int n,m,sum,cnt,ans;
int a[500];
bool cmp(int w,int k)
{
	return w>k;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n*m; i++)
	{
		scanf("%d",&a[i]);
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++)
	{
		if(a[i]==sum)
		{
			sum=i;
			break;
		}
	}
	if(sum%n==0)
	{
		cnt=sum/n;
	}
	else
	{
		cnt=sum/n+1;
	}
	if(cnt%2==0)
	{
		ans=n*cnt-sum+1;
	}
	else
	{
		ans=n-(n*cnt-sum);
	}
	printf("%d %d",cnt,ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
