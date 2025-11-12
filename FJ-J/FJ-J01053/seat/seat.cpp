#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,nm,f=1;
struct st
{
	int num,dcl;
}stu[105];
bool cmp(st x,st y){return x.dcl>y.dcl;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	nm=n*m;
	for(int i=1;i<=nm;i++)
	{
		scanf("%d",&stu[i].dcl);
		stu[i].num=i;
	}
	sort(stu+1,stu+1+nm,cmp);
	int x=1,y=1;
	bool flag=false;
	for(int i=1;i<=nm;i++)
	{
		if(stu[i].num==1)
		{
			printf("%d %d",y,x);
			return 0;
		}
		if(!flag)
		{
			x+=f;
			if(x==n||x==1)
			{
				flag=true;
			}
		}
		else
		{
			y++;
			flag=false;
			f*=-1;
		}
	}
	return 0;
}

