#include<bits/stdc++.h>
using namespace std;
char a[1000005];
char f[1000005];
int s[1000005];
char u[1000005];
int cnt=0;
int ans;
int main()
{
	
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>a[i];
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
      cin>>u[i];
      
     }
     for(int i=1;i<=n;i++)
     {
	   if(s[i]==0)
	   {
		  f[i]=0;
		  cnt++;
		}	
		if(a[i]<a[i-1]+a[i-2])
		{
			f[i]=0;
		} 
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
		  ans++;	
		}
	}
	cout<<ans;
	return 0;
}
