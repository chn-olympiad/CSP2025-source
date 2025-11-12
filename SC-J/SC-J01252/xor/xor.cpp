#include<bits/stdc++.h>
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
using namespace std;
int n,k,a[500010],sum,ans;
bool flag;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	I AK CSP
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		sum+=a[i];
		if(a[i]==0) flag=true;
	}
	if(k==0)
	{
		if(flag)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) ans++;
				else if(a[i+1]==1) ans++,i++;
			}
		}
		else ans=sum/2;
	}
	else if(k==1) ans=sum;
	cout<<ans;
	return 0;
}