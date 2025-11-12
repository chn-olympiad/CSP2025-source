#include <bits/stdc++.h>
using namespace std;
int n,val;
int a[500005];
int book[500005];
int cnt,num;
int finalans;
int ans;
int flag,flag2;
void find(int e)
{
	ans=0;
	num=e;
	while(ans!=val)
	{
		num++;
		if(num>n)
		{
			return ;
		}
		ans^=a[num];
	}
	if(ans==val)
	{
		cnt++;
		find(num);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>val;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]==1) flag++;
		if(a[i]==0) flag2++;
	}
	if(flag==n)
	{
		if(val==0)
		{
			cout<<n/2;
		}
		else if(val==1)
		{
			cout<<n;
		}
		return 0;
	}
	if((flag+flag2)==n)
	{
		if(val==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) cnt++;
				if(a[i]==1&&book[i-1]==0&&a[i-1]==1) 
				{
					cnt++;
					book[i]=1;
				}
			}
			cout<<cnt;
		}
		else if(val==1)
		{
			cout<<flag;
		}
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cnt=0;
		find(i);
		finalans=max(finalans,cnt);
	}
	cout<<finalans;
	return 0;
}

