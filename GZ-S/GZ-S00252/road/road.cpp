//GZ-S00252 毕节东辰实验学校 杜文豪
#include <bits/stdc++.h>
using namespace std;
struct no
{
	int x,y;
	long long wei;
}ed[3000000];
int tot=0;

struct od
{
	int num,fa;
}nod[20000];

int a,b,c;
void build(int x,int y,int wei)
{
	ed[++tot].x=x;
	ed[tot].y=y;
	ed[tot].wei=wei;
}
bool cmp(no x,no y)
{
	return x.wei<y.wei;
}
int get(int p)
{
	if(nod[p].fa!=p)
	{
		nod[p].fa=get(nod[p].fa);
	}
	return nod[p].fa;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>a>>b>>c;
	for(int n=1;n<=a;n++)
	{
		nod[n].fa=n;
		nod[n].num=1;
	}
	for(int n=1;n<=b;n++)
	{
		int x,y,we;
		cin>>x>>y>>we;
		build(x,y,we);
	}
	sort(ed+1,ed+1+b,cmp);
	long long ans=0;
	for(int n=1;n<=b;n++)
	{
		int fx=get(ed[n].x);int fy=get(ed[n].y);
		if(fx!=fy)
		{
			nod[fx].fa=fy;
			nod[fy].num+=nod[fx].num;
			ans+=ed[n].wei;
		}
		if(nod[fy].num==a)
		{
			cout<<ans;
			break;
		}
	}
}
/*
5 8 0
2 3 1
3 5 1
5 4 1
4 2 1
1 2 999
1 3 999
1 4 999
1 5 999
*/
