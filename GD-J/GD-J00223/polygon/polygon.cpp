#include<bits/stdc++.h>
using namespace std;
int n,k,a[10005],q[10005];
int cnt;
int My_max(int x,int y)
{
	return x>y?x:y;
}
void kuaipai(int l,int r)
{
	int i=l,j=r,mid=a[(l+r)/2];
	while(i<=j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;j--;
		}
	}
	if(i<r) kuaipai(i,r);
	if(l<j) kuaipai(l,j); 
}
void dfs(int id,int sum,int biao)
{
	if(sum<=biao) return ;
	if(id==0)
	{
		cnt++;cnt%=998244353;
		return ;
	}
	dfs(id-1,sum-a[id],biao);
	dfs(id-1,sum,biao);
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 
	} 
	kuaipai(1,n);
	for(int i=1;i<=n;i++)
	{
		q[i]=q[i-1]+a[i];
	}
	for(int i=3;i<=n;i++)
	{
		if(q[i-1]<=a[i]) continue;
		dfs(i-1,q[i-1],a[i]);
	}
	cout<<cnt;
	return 0;
}

