#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int a[N],n,m,r;
struct student{
	int cj,x,y;
} stu[N];
int fy=1;
bool cmp(int x,int y)
{
	if(x>y)return 1;
	else return 0;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	stu[1].cj=a[1];
	stu[1].x=stu[1].y=1;
	for(int i=2;i<=n*m;i++)
	{
		stu[i].cj=a[i];
		stu[i].y=stu[i-1].y+fy;
		stu[i].x=stu[i-1].x;
		if(stu[i].y>n||stu[i].y<1){
			stu[i].x++;
			stu[i].y-=fy;
			fy*=-1;
		}
		if(stu[i].cj==r)
		{
			cout<<stu[i].x<<" "<<stu[i].y;
			return 0;
		}
	}
	return 0;
}
