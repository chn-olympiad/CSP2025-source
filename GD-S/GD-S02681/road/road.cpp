#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k;
int u[N],v[N],w[N];
int a[N] c[N];
bool flag=flase;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>u[i]>>v[i]>>w[i]; 
	}
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			if(a[j]!=0)
			{
				flag=flase;
			}
			if(!a[j])
			{
				flag=true;
			}
		}
	}
	cout<<w[1];
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
