#include<bits/stdc++.h>
using namespace std;
int n,d,a[5005],ans,v[5005];
void dfs(int x,int sum,int mx,int xx)
{
	if(sum>mx*2&&x>3&&xx==1)
	{
		ans++;
//		cout<<"Ok"<<endl;
	}
	if(x>n)
	{
		return;
	}
//	printf("选了%d\n",x);
	dfs(x+1,sum+a[x],max(mx,a[x]),1);
//	printf("不选%d\n",x);
	dfs(x+1,sum,mx,0);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	d=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		d=max(a[i],d);
	}
	if(d==1)
	{
		for(int i=2;i<n;i++)
		{
			ans+=n-i;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
} 
/*
6 
1 1 1 1 1 1

10
*/
