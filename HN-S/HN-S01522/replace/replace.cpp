#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,q,c[MAXN],ans,bl;
struct chuan
{
	string a1,a2;
}a[MAXN],b[MAXN];
string a1,a2,a3;
string b1,b2,b3;
void dfs(int x)
{
	for(int i=0;i<bl;i++)
	{
		if(c[i+1]==0)
		{
			for(int j=1;j<=3;j++)
			{
				for(int t=1;t<=3;t++)
				{
					if(j==1&&t==1) return;
					if(j==2&&t==1) return;
					if(j==3&&t==1) return;
				    if(j==1&&t==2) return;
				    if(j==2&&t==2) return;
				    if(j==3&&t==2) return;
				    if(j==1&&t==3) return;
				    if(j==2&&t==3) return;
				    if(j==3&&t==3) return;
				}
			}
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) cin>>a[i].a1>>a[i].a2;
	for(int i=1;i<=q;i++) 
	{
		cin>>b[i].a1>>b[i].a2;
		int bl=b[i].a1.size();
		dfs(1);
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}
