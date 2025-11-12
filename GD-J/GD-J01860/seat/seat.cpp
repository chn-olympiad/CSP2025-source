#include<bits/stdc++.h>
using namespace std;
struct mb
{
	int se,num;
}a[105];
struct stt
{
	int x,y;
}b[105];
int n,m;
string st;
bool cmp(mb xx,mb yy)
{
	return xx.se>yy.se;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) scanf("%lld",&a[i].se),a[i].num=i;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(((i-1)/m+1)%2==1)
		b[a[i].num].x=(i-1)/m+1,b[a[i].num].y=(i-1)%m+1;
		else b[a[i].num].x=(i-1)/m+1,b[a[i].num].y=m-((i-1)%m);
	}
	cout<<b[1].x<<" "<<b[1].y;
	return 0;
 } 
