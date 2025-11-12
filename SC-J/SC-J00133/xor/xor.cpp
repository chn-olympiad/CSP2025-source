#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie();cin.tie();
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	int ans=0,ll=1;
	for(int r=1;r<=n;r++)
	{
		for(int l=ll;l<=r;l++)
		{
			if((b[r]^b[l-1])==k)
			{
				//cout<<l<<" "<<r<<(b[r]^b[l-1])<<((b[r]^b[l-1])==k)<<"\n";
				//cout<<l<<" "<<r<<"\n";
				ans++;
				ll=r+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}