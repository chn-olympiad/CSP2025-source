#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1e7+10;
int n,k,a[N],m;
struct Node{
	int l,r;
}p[M];
bool cmp(Node s,Node j)
{
	return s.r<j.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<10000)
	{
		for(int i=1;i<=n;i++)
		{
			int x=0;
			for(int j=i;j<=n;j++)
			{
				x^=a[j];
				if(x==k)
				{
					p[++m].l=i;
					p[m].r=j;
				}
			}
		}
		sort(p+1,p+m+1,cmp);
		int las=1,cnt=1;
		for(int i=2;i<=m;i++)
		{
			if(p[las].r<p[i].l)
			{
				cnt++;
				las=i;
			}
		}
		printf("%d",cnt);
	}
	else
	{
		int x=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			x^=a[i];
			if(x==k)
			{
				cnt++;
				x=0;
			}
		}
		printf("%d",cnt);
	}
	return 0;
}
