#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}r[100005];

struct node2{
	int cz,id,by,byz;
};

bool px(node2 a,node2 b)
{
	return a.cz<b.cz;
}

node2 x[4][50005];
int y[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		y[1]=0;
		y[2]=0;
		y[3]=0;
		for(int i=1;i<=n;i++)
		{
			int q,w,e;
			cin>>q>>w>>e;
			r[i].a=q;
			r[i].b=w;
			r[i].c=e;
			node2 mx,sx,fx;
			mx.cz=2*q-w-e;
			sx.cz=2*w-e-q;
			fx.cz=2*e-q-w;
			mx.id=1;
			sx.id=2;
			fx.id=3;
			if(mx.cz<fx.cz)
			{
				node2 s=mx;
				mx=fx;
				fx=s;
			}
			if(sx.cz<fx.cz)
			{
				node2 s=sx;
				sx=fx;
				fx=s;
			}
			if(y[mx.id]==n/2)
			{
				sort(x[mx.id],x[mx.id]+y[mx.id],px);
				if(x[mx.id][n/2-1].cz<mx.cz)
				{
					node2 s;
					s.cz=x[mx.id][n/2-1].by;
					s.id=x[mx.id][n/2-1].id;
					x[x[mx.id][n/2-1].byz][y[x[mx.id][n/2-1].byz]]=s;
					y[x[mx.id][n/2-1].byz]++;
					s.cz=mx.cz;
					s.id=i;
					s.by=sx.cz;
					x[mx.id][n/2-1]=s;
				}
				else
				{
					node2 s;
					s.cz=sx.cz;
					s.id=i;
					x[sx.id][y[sx.id]]=s;
					y[sx.id]++;
				}
			}
			else
			{
				node2 s;
				s.cz=mx.cz;
				s.id=i;
				s.by=sx.cz;
				s.byz=sx.id;
				x[mx.id][y[mx.id]]=s;
				y[mx.id]++;
			}
		}
		sort(x[1],x[1]+y[1],px);
		sort(x[2],x[2]+y[2],px);
		sort(x[3],x[3]+y[3],px);
		//cout<<x[1][1].cz;
		int ans=0;
		for(int i=0;i<y[1];i++)
		{
			ans+=r[x[1][i].id].a;
		}
		//cout<<ans<<' ';
		for(int i=0;i<y[2];i++)
		{
			ans+=r[x[2][i].id].b;
		}
		//cout<<ans<<' ';
		for(int i=0;i<y[3];i++)
		{
			ans+=r[x[3][i].id].c;
		}
		cout<<ans<<endl;
	}
	return 0;
}
