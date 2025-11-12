#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int h;
	int c;
	int r;
}stu[105];
bool cmp(node x,node y)
{
	return x.a>y.a;
}
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>stu[i].a;
		stu[i].h=i;
	}
	sort(stu+1,stu+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(stu[i].h==1)
		{ 
			stu[i].c=(i-1)/n+1;
			if(stu[i].c%2)
				stu[i].r=(i-1)%n+1;
			else
				stu[i].r=n-i%n+1;
			cout<<stu[i].c<<" "<<stu[i].r;
		}
	}
}