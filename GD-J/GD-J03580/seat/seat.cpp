#include<bits/stdc++.h>
using namespace std;
int c,r;
struct Node
{
	int a,num; 
};
Node x[110];
bool cmp(Node aa,Node bb)
{
	return aa.a>bb.a;
} 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>x[i].a;
		x[i].num=i;
	}
	sort(x+1,x+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(x[i].num==1)
		{
			int teb=i;
			while(teb>0)
			{
				teb=teb-n;
				c++;
			}
			int f=i%n;
			if(c%2==0)
			{
				if(f==0)
				{
					r=1;
				}
				else
				{
					r=n-f+1;
				}
			}
			else
			{
				if(f==0)
				{
					r=n;
				}
				else
				{
					r=f;
				}
			}
		}
	}
	cout<<c<<' '<<r;
return 0;
}
