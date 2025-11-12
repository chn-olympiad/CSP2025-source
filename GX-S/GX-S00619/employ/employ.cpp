#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int T,n,v,k,ans=0;
int a[100010][3],f[200][200][200];
int main()
{
	freopen("club1.in","r",stdin);
	//freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
			cout<<a[i][0]<<' '<<a[i][1]<<' '<<a[i][2]<<'\n';
		}
		v=n>>1;
		ans=0;
		memset(f,0,8000000);
		for(int i=0;i<n;i++)
		{
			for(int b=0;b<=i;b++)
			for(int d=0;d<=i-b;d++)
			{
				register int* g=&f[i][b][d];
				register int u=i-b-d;
				*g=max(*g,f[i-1][b-1][d]+a[i][0]);
				*g=max(*g,f[i-1][b][d-1]+a[i][1]);
				if(u<=v)*g=max(*g,f[i-1][b][d]+a[i][2]);
			}
		}
		n--;
		for(int b=0;b<=v;b++)
		for(int d=0;d<=v-b;d++)
		{
			ans=max(ans,f[n][b][d]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
