#include <bits/stdc++.h>
using namespace std;
int book[2000005];
int can[500005];
struct node
{
	int x,y,xo;
}q[2000005];
int a[500005];
int n,k;
void bulid(int x,int l,int r)
{
	int mid=(l+r)/2;
	q[x].x=l;
	q[x].y=r;
	if(l==r)
	{
		q[x].xo=a[l];
		return;
	}
	bulid(x*2,l,mid);
	bulid(x*2+1,mid+1,r);
	q[x].xo=q[x*2].xo^q[x*2+1].xo;
}
int check(int x)
{
	int sum=0;
	if(q[x].x==q[x].y && q[x].xo!=k)
		return 0;
	if(book[x])
		sum=book[x];
	if(q[x].xo==k)
	{
		can[q[x].x]=1;
		can[q[x].y+1]=-1;
		sum=1;
	}
	return book[x]=sum+check(x*2)+check(x*2+1);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int maxn=0,zero=0;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
		cin >> a[i];
		if(a[i]==0) zero=1;
		maxn=max(maxn,a[i]);
	}
    if(k==1 && maxn==1)
    {
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			{
				cnt++;
			}
		}
		cout << cnt;
		return 0;
	}
	if(k==0 && maxn==1 && zero)
    {
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(!a[i])
			{
				cnt++;
			}
		}
		for(int i=1;i<n;i++)
		{
			if(a[i]==1 && a[i+1]==1)
			{
				cnt++;
				i++;
			}
		}
		cout << cnt;
		return 0;
	}
	if(k==0 && maxn==1 && !zero)
    {
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			{
				cnt++;
			}
		}
		cout << cnt/2;
		return 0;
	}
    bulid(1,1,n);
    int sum=check(1);
    sum++;
    sum--;
    cout << sum;
    return 0;
}
