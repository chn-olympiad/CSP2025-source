#include <bits/stdc++.h>

using namespace std;
int n;
int a[5005];
int alladd=0,ans=0;
void tofind(int many,int which,int biggest)
{
	for(int i=which+1;i<=n;i++)
	{
		if(n-i>=many-1)
		{
			alladd+=a[i];
			if(many-1==0)
			{
				if(alladd>2*max(biggest,a[i]))
				{
					ans++;
					ans%=998244353;
				}
			}
			else
			{
				tofind(many-1,i,max(biggest,a[i]));
			}
			alladd-=a[i];
		}
	}
	return;
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
	for(int i=3;i<=n;i++)
	{
		tofind(i,0,0);
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
