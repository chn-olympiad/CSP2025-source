#include<bits/stdc++.h>
using namespace std;
int t,l[11],f,n;
struct q{
	int a;
	int b;
	int c;
	int t=1;
};
bool cmp(q x,q y)
{
	return x.a>y.a;
}
bool cmp1(q x,q y)
{
	return x.b>y.b;
}
bool cmp2(q x,q y)
{
	return x.c>y.c;	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	q h[100100];
	while(t--)
	{
		int ax=0,bx=0,cx=0,s=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>h[i].a>>h[i].b>>h[i].c;
		}
		if(n==2)
		{
			int t1=max(h[1].a+h[2].b,h[1].a+h[2].c);
			int t2=max(h[1].b+h[2].a,h[1].b+h[2].c);
			int t3=max(h[1].c+h[2].a,h[1].c+h[2].b);
			l[++f]=max(t1,max(t2,t3));
			continue;
		} 
		sort(h+1,h+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(h[i].a>h[i].b && h[i].a>h[i].c && ax<n/2)
			{
				ax++;
				s+=h[i].a;
				h[i].t=0;
			}			
		}
		sort(h+1,h+1+n,cmp1);
		for(int i=1;i<=n;i++)
		{
			if(h[i].b>h[i].a && h[i].b>h[i].c && bx<n/2)
			{
				bx++;
				s+=h[i].b;
				h[i].t=0;
			}			
		} 
		sort(h+1,h+1+n,cmp2);
		for(int i=1;i<=n;i++)
		{
			if(h[i].c>h[i].a && h[i].c>h[i].b && cx<n/2)
			{
				cx++;
				s+=h[i].c;
				h[i].t=0;
			}			
		}
		if(ax+bx+cx==n)
		{
			l[++f]=s;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(!h[i].t)
				continue;
			if(ax<n/2 && bx>=n/2 && cx>=n/2)
				s+=h[i].a;
			else if(ax<n/2 && bx<n/2 && cx>=n/2)
				s=s+max(h[i].a,h[i].b);
			else if(ax<n/2 && bx>=n/2 && cx<n/2)
				s=s+max(h[i].a,h[i].c);
			else if(ax>=n/2 && bx<n/2 && cx<n/2)
				s=s+max(h[i].b,h[i].c);
			else if(bx<n/2 && ax>=n/2 && cx>=n/2)
				s+=h[i].b;
			else if(cx<n/2 && bx>=n/2 && ax>=n/2)
				s+=h[i].c;
		}	
		l[++f]=s;
	}
	for(int i=1;i<=f;i++)
		cout<<l[i]<<"\n";
	return 0;
} /*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4 
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0
*/
