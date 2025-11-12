#include<bits/stdc++.h>
using namespace std;
int n,a[10000],t=-1,b[10000],z;
long long ans=0;
void DFS(int d,int x)
{
	if(d==n)
	  return ;
	for(int i=d+1;i<=n;i++)
	{
		t=-1;
		z=0;
		b[x+1]=a[i];
		for(int j=1;j<=x+1;j++)
		{
			if(b[j]>t)
			{
				t=b[j];
			}
			z+=b[j];
		}
		if(z>t*2)
		{
			ans++;
		}
		ans=ans%998244353;
		DFS(i,x+1);
		b[x+1]=0;
	}
	return ;
 } 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	DFS(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}