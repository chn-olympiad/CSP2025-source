#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int xx,k;
}a[100002];
bool cmp(node x,node y)
{
	return x.xx>y.xx;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].xx;
		a[i].k=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int sum,cnt,res;
	for(int i=1;i<=n*m;i++)
		if(a[i].k==1)
			sum=i;
	res=sum/(n*2);
	cnt=sum%(n*2);
	if(res==0)
	{
		if(cnt<=n)
		{
			cout<<1<<" "<<cnt;
			return 0;
		}
		if(cnt>n)
		{
			cnt=cnt-n;
			cout<<2<<" "<<n-cnt+1;
			return 0;
		}
	}
	if(res>0)
	{
		if(cnt==0)
		{
			cout<<res*2<<" "<<1;
		}
		else if(cnt<=n)
		{
			cout<<2*res+1<<" "<<cnt;
		}
		else if(cnt>n)
		{
			cnt=cnt-n;
			cout<<res*4<<" "<<n-cnt+1;
		}
	}
	return 0;
}
