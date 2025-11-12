#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000100];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>n>>m;
	int k=0,x=0,ans=0;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		int y=0;
		cin>>y;
		x^=y;
		if(a[x^m]>=k)
		{
			k=i;
			ans++;
		}
		a[x]=i;
	}
	cout<<ans;
	return 0;
}
