#include<bits/stdc++.h>
using namespace std;
int a[500010],xs[500010];
int n,k,pos,ans;
int main()
{
	//by FLtops
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		xs[i]=xs[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=pos+1;j<=i;j++)
		{
			if((xs[i]^xs[j-1])==k)
			{
				ans++;
				pos=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

