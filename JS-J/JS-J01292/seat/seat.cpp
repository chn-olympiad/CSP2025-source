#include <bits/stdc++.h>
using namespace std;
int n,m,s,id,ans1,ans2,cc;
bool flag;
struct student
{
	int x,y,score;
}q[105];
bool cmp(student a,student b)
{
	return a.score>b.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	q[1].score=s;
	for(int i=2;i<=n*m;i++)
	{
		cin>>q[i].score;
	}
	sort(q+1,q+n*m+1,cmp);
	/*
	for(int i=1;i<=n*m;i++)
	{
		cout<<q[i].score<<' ';
	}
	*/
	//cout<<endl;
	flag=true;
	int xx=1,yy=1;
	for(int i=1;i<=n*m;i++)
	{
		if(flag)
		{
			if(xx>n)
			{
				q[i].x=--xx;
				q[i].y=++yy;
				flag=false;
				if(q[i].score==s)
				{
					cout<<q[i].y<<' '<<q[i].x;
					return 0;
				}
				i--;
				continue;
			} 
			q[i].x=xx;
			q[i].y=yy;
			xx++;
		}
		else
		{
			if(xx<1)
			{
				q[i].x=++xx;
				q[i].y=++yy;
				flag=true;
				if(q[i].score==s)
				{
					cout<<q[i].y<<' '<<q[i].x;
					return 0;
				}
				i--;
				continue;
			} 
			q[i].x=xx;
			q[i].y=yy;
			xx--;
		}
		//cout<<q[i].x<<' '<<q[i].y<<' '<<q[i].score<<' '<<endl;
		if(q[i].score==s)
		{
			cout<<q[i].y<<' '<<q[i].x;
			return 0;
		}
	}
}
