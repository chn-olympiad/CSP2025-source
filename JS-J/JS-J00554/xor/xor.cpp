#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],maxx=-1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int s=0,cnt=0;
		for(int j=i;j<=n;j++)
		{
			s=s^a[j];
			if(s==k) {cnt++;s=0;}
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}
