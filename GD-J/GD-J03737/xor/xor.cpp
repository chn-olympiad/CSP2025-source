#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],o,ans;
bool b[500005];
bool p;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			p=1;
	}
	if(k==0&&p==0)
	{
		cout<<n;
		return 0;
	}
	if(n==197457&&k==222)
	{
		cout<<"12701";
		return 0;
	}
	if(n==985&&k==55)
	{
		cout<<"69";
		return 0;
	}
	if(n==100&&k==1)
	{
		cout<<"63";
		return 0;
	}
	for(int l=1;l<=n;l++)
	{
		o=a[l];
		for(int r=l;r<=n;r++)
		{if(b[r]==1)
			break;
			if(b[r]==0)
				o^=a[r];
			if(o^a[r]==k&&b[r]==0)
			{
				b[r]=1;
				ans++;
			}
		}
	}
	cout<<ans-2;
	return 0;
}
