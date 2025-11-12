#include<bits/stdc++.h>
using namespace std;
int n,dad[200005],m,ans,a[25][200005],mm,z[25],tt;
struct no
{
	int x,y,z;
}s[200005];
bool cmp(no x,no y)
{
	return x.z<y.z;
}
int fd(int x)
{
	if(dad[x]!=x) dad[x]=fd(dad[x]);
	return dad[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mm);
	for(int i=1;i<=n;i++)
	{
		dad[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].z);
	}
	for(int i=1;i<=mm;i++)
	{
		for(int j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	}
	stable_sort(s+1,s+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int s1=fd(s[i].x),s2=fd(s[i].y);
		if(s1!=s2)
		{
			dad[s1]=s2;
			ans+=s[i].z;
		}
	}
	printf("%d",ans);
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
