#include <bits/stdc++.h>
using namespace std;
long long int a[5000+10];
long long int flag[5000+10];
long long int n,ans=0;
void f(int x,int y,int z,int o){
	if(x==z-1)
	{
		for(int i=o;i<=n;i++)
		{
			if(a[i]<y&&flag[i]==0)
			{
				ans++;
			    ans=ans%998244353;
			}
		}
		return ;
	}
	if(y==n)
	{
		return ;
	}
	for(int i=o;i<=n;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=1;
			f(x+1,y+a[i],z,i+1);
			flag[i]=0;
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
	for(int i=3;i<=n;i++)
	{	
		f(0,0,i,1);
	}
	cout<<ans+1<<endl;
	return 0;
}
