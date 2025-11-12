#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int n,m;
int xx,yy,p;
struct node
{
	int x;
	bool f;
} a[MAXN];
bool cmp(node aa1,node aa2)
{
	return aa1.x>aa2.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1].x,a[1].f=1;
	for(int i=2;i<=n*m;i++)
			cin>>a[i].x;
	sort(a+1,a+n*m+1,cmp);
	xx=p=1;
	for(int i=1;i<=n*m;i++)
	{
		yy+=p;
		if(yy>n) xx++,yy--,p=-1;
		if(yy<1) xx++,yy++,p=1;
		if(a[i].f)
		{
			cout<<xx<<" "<<yy;
			return 0;
		}
	}
	return 0;
}
