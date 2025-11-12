#include<bits/stdc++.h>
using namespace std;
int a[500010];
int sum=0;
int n,k;
int t=0;
struct wuchangle
{
	int x,y;
};
wuchangle temp[500010];
int func(int l,int r)
{
	int n;
	n=a[l];
	for(int i=l+1;i<=r;i++)
	{
		n=n^a[i];
	}
	return n;
}
bool cmp(wuchangle a,wuchangle b)
{
	return a.y<b.y;
}
int find(int l,int count)
{
	int tmp=temp[l].y;
	for(int i=l+1;i<=count;i++)
	{
		if(temp[i].x>tmp)
		{
			return i;
		}
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int count=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(func(i,j)==k)
			{
				temp[count].x=i;
				temp[count++].y=j;
			}
			if(j==n)
			{
				break;
			}
		}
	}
	if(count==1)
	{
		cout<<0;
		return 0;
	}
	count--;
	sort(temp+1,temp+count,cmp);
	for(;;)
	{
		t=find(t,count);
		if(t==0)
		{
			cout<<sum;
			return 0;
		}
		sum++;
	}
	return 0;
}
