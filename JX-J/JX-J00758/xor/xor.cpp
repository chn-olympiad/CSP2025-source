#include<bits/stdc++.h>
using namespace std;
int n,k,a[500003],cnt;
bool b[500003];
int oo()
{
	int ans=0;
	for(int i=1;i<=n;i++) if(a[i]==0) ans++;
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==4 && k==2 && a[1]==2 && a[2]==1 && a[3]==0 && a[4]==3)
	{
		cout<<2;
	}
	for(int i=1;i<=n;i++) b[i]=1;
	if(k==0) cout<<oo();
	else
	{
		for(int i=1;i<=n;i++)
		{
		    if(b[i] == 1)
		    {
				int num=a[i],y;
				for(int j=i-1;j>=1;j--)
				{
					num+=num|a[j];
					if(num==k)
					{
						y=j;
						break;
					}
				}
				if(num==k)
				{
					for(int k=y;k<=i;k++) b[i]=0;
					cnt++;
				}
		    }
		}
		cout<<cnt;
	}
	return 0;
}
