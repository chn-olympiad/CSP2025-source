#include<bits/stdc++.h>
using namespace std;
struct node
{
	int f,id;
	friend const operator < (node a,node b)
	{
		return a.f<b.f;
	}
};
priority_queue<node>q;
int n,m,x,sum=0,h=1,l=1;
bool flag=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>x;
		q.push({x,i});
	}
	while(q.top().id!=1)
	{
		if(!flag&&h!=n)h++;
		else if(!flag&&h==n)
		{
			flag=1;
			l++;
		}
		else if(flag&&h!=1)h--;
		else if(flag&&h==1)
		{
			l++;
			flag=0;
		}
		q.pop();
	}
	cout<<l<<' '<<h;
}