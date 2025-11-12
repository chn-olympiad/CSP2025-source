#include <bits/stdc++.h>
using namespace std;
int t,n;
int cnt=0;
struct p
{
	int d1,d2,d3;
}a[2000005];
bool cmpA(p m,p n)
{
	return m.d1>n.d1;
}
long long int dfs(int i,int n1,int n2,int n3,long long int ans)
{
	if(i>n||cnt>=10000000)
		return ans;
	long long int nans=ans;
	cnt++;
	if(n1+1<=n/2)
		nans=max(nans,dfs(i+1,n1+1,n2,n3,ans+a[i].d1));
	if(n2+1<=n/2)
		nans=max(nans,dfs(i+1,n1,n2+1,n3,ans+a[i].d2));
	if(n3+1<=n/2)
		nans=max(nans,dfs(i+1,n1,n2,n3+1,ans+a[i].d3));
	return nans;
}
long long int dfsB(int i,int n1,int n2,long long int ans)
{
	if(i>n||cnt>=10000000)
		return ans;
	cnt++;
	long long int nans=ans;
	if(n1+1<=n/2)
		nans=max(nans,dfsB(i+1,n1+1,n2,ans+a[i].d1));
	if(n2+1<=n/2)
		nans=max(nans,dfsB(i+1,n1,n2+1,ans+a[i].d2));
	return nans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long int ans=0;
	cin>>t;
	while(t--)
	{
		cnt=0;
		cin>>n;
		bool A=1,B=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			if(a[i].d3!=0){B=0;}
			if(a[i].d3!=0||a[i].d2!=0){A=0;}
		}
		if(n<=35)
		{
			cout<<dfs(1,0,0,0,0)<<endl;
		}
		else if(A)
		{
			sort(a+1,a+n+1,cmpA);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].d1;
			}
			cout<<ans<<endl;
		}
		else if(B)
		{
			cout<<dfsB(1,0,0,0)<<endl;
		}
		else
		{
			cout<<dfs(1,0,0,0,0)<<endl;
		}
	}
	return 0;
}
