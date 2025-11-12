#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("roud.in","r",stdin);
	freopen("roud.out","w",stdout);
	int n,m,k,v[100001],v1[100001],v2[10001],z,ans;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>v[i]>>v1[i]>>v2[i];
		if(v[i]<v1[i])
		{
			swap(v[i],v1[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
		if(v[j]==i)
		{
			ans+=v2[i];
		}
	}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
