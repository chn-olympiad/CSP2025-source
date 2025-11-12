//seat
#include<bits/stdc++.h>
using namespace std;
int n,m,r,re[102];
inline bool cmp(int a,int b){return a>b;}
int seat(int p)
{
	if(((p-1)/n)%2==0)printf("%d %d",(p-1)/n+1,(p-1)%n+1);
	else printf("%d %d",(p-1)/n+1,m-((p-1)%m));
	return 0;
}
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&r);
	re[1]=r;
	for(int i=2;i<=n*m;i++)
	{
		scanf("%d",&re[i]);
	}
	sort(re+1,re+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(re[i]==r)
		{
			//printf("%d\n",i);
			seat(i);
		}
	}
	return 0;
}
