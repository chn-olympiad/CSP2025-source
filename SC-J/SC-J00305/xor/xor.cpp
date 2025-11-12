#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int a[N];
bool vis[N];
long long ppow(int a,int b)
{
	if(b==0)
	{
		return 1;
	}
	if(b==1)
	{
		return a;
	}
	int t=a;
	for(int i=1;i<b;i++)
	{
		a*=t;
	}
	return a;
}
int xr(int a,int b)
{
	if(a>=b)
	{
		swap(a,b);
	}
	int tempa[10005],tempb[10005],ending[10005],end;
	for(int i=1;ppow(2,i-1)<=b;i++)
	{
		if(ppow(2,i-1)>a)
		{
			tempa[i]=0;	
		} 
		else
		{
		tempa[i]=a%2;
		a/=2;	
		}
	}
	for(int i=1;pow(2,i-1)<=b;i++)
	{
		tempb[i]=b%2;
		b/=2;
	}
	for(int i=1;ppow(2,i-1)<=b;i++)
	{
		if(tempa[i]==tempb[i])
		{
			ending[i]=0;
		}
		else
		{
			ending[i]=1;
		}
	}
	for(int i=1;ppow(2,i-1)<=b;i++)
	{
		ending[i]=ppow(2,i-1);
		end+=ending[i];
	}
	return end;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			ans++;
			vis[i]=1;
		}
	}
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			flag=1;	
			continue;
		}
		else
		{
			a[i]=xr(a[i],a[i-1]);
			if(a[i]==0&&flag)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}