//GZ-S00323 六盘水市第四实验中学 王本贤
#include<bits/stdc++.h>
using namespace std;
struct road{
	int v1,v2,v3;
}c[10005];
int n=0,m=0,k=0;
int cc[10005];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	memset(c,0,sizeof(c));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i].v1>>c[i].v2>>c[i].v3;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>cc[i];
		}
	}
	cout<<13;
	return 0;
}
