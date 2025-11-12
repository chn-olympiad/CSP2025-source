#include<bits/stdc++.h>
using namespace std;
int n,a[100000],b[100000],cnt=0;
/*bool cmp(int a,int b)
{
	if(a>=b)return 1;
	return 0;
}*/
void dfs(int deep,int s,int ma,int st)
{
	if(deep==n+1)return;
	if(s>ma*2)
	{
		cnt++;
	}
	for(int i=st;i<n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			if(a[i]>ma)dfs(deep+1,s+a[i],a[i],i);
			else dfs(deep+1,s+a[i],ma,i);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
//	sort(a,a+n,cmp);
	dfs(0,0,0,0);
	cout<<cnt;
	return 0;
}
