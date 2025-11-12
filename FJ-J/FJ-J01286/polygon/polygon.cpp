#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;bool vis[5005];int viss[5000][5000];int y[5000][5000];
void f(int step,int all,int maxnn)
{
	
	if(step>=3)
	{
		if(all>maxnn*2)
		{
			
			ans++;
		}
	}
	if(step==n)
	{
		return;
	}
	for(int j=1;j<=n;j++)
	{
		if(!vis[j])
		{
			vis[j]=1;
			f(step+1,all+a[j],max(a[j],maxnn));
			vis[j]=0;
		}
		
	}
	
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
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		f(1,i,i);
		vis[i]=0;
	}
	cout<<ans/2%998244353;
}
 
