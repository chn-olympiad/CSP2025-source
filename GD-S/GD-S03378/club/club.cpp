#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
struct node{int a,b,c;}d[N];
bool cmp(node x,node y){return x.a>=y.a;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)
	{
		int n,ans=0,pd=0;scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
			if(d[i].b!=0&&d[i].c!=0)pd=1;
			int mm=max(d[i].a,max(d[i].b,d[i].c));
			ans+=mm;
		}
		if(pd==0)
		{
			sort(d+1,d+n+1,cmp);
			for(int i=1;i<=n/2;i++)pd+=d[i].a;
			printf("%d",pd);
		}
		else printf("%d",ans);
	} 
}
/*
1
4 
4 2 1 
3 2 4 
5 3 4 
3 5 1
*/
