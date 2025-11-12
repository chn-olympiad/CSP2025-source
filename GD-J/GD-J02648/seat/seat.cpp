#include<bits/stdc++.h>
#define fre(x) \
	freopen(x".in","r",stdin); \
	freopen(x".out","w",stdout)
#define ll long long
#define il inline
using namespace std;

const int MAXN=1e2+7;

int n,m,a[MAXN*MAXN],r;

bool cmp(int x,int y) {return x>y;}

int main()
{
	fre("seat");
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int tot=0,op=0;
	for(int i=1;i<=m;i++)
	{
		op^=1;
		if(op)
		{
			for(int j=1;j<=n;j++)
			{
				++tot;
				if(a[tot]==r)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				++tot;
				if(a[tot]==r)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
