#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[114514];
	int v[114514];
	int w[114514];
	int a[114514];
	int c[114514];
	for(int i;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j;j<=k;j++)
	{
		cin>>c[j]>>a[j];
		if(c[j]>a[j])
		{
			cout<<a[j]<<endl;
		}
		else if(a[j]>c[j])
		{
			cout<<c[j]<<endl;
		}
		else
		{
			cout<<a[j]<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
