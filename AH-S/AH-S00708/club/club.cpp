#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node{
	int a,b,c,d;
	int cha;
	int e;
	int id1,id2;
};
Node x[N];
bool cmp(Node k,Node l)
{
	return k.cha>l.cha;
}
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
		for(int i=1;i<=n;i++)
		{
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a>=x[i].b&&x[i].a>=x[i].c)
			{
				x[i].d=x[i].a;
				x[i].id1=1;
				if(x[i].b>=x[i].c)
				{
					x[i].e=x[i].b;
					x[i].id2=2;
				}
				else
				{
					x[i].e=x[i].c;
					x[i].id2=3;
				}
			}
			if(x[i].b>=x[i].a&&x[i].b>=x[i].c)
			{
				x[i].d=x[i].b;
				x[i].id1=2;
				if(x[i].a>=x[i].c)
				{
					x[i].e=x[i].a;
					x[i].id2=1;
				}
				else
				{
					x[i].e=x[i].c;
					x[i].id2=3;
				}
			}
			if(x[i].c>=x[i].b&&x[i].c>=x[i].a)
			{
				x[i].d=x[i].c;
				x[i].id1=3;
				if(x[i].b>=x[i].a)
				{
					x[i].e=x[i].b;
					x[i].id2=2;
				}
				else
				{
					x[i].e=x[i].a;
					x[i].id2=1;
				}
			}
			x[i].cha=x[i].d-x[i].e;
		}
		sort(x+1,x+1+n,cmp);
		long long ans=0;
		int op=n/2;
		int sa=0,sb=0,sc=0;
		for(int i=1;i<=n;i++)
		{
			if(x[i].id1==1)
			{
				sa++;
				if(sa>op)
				{
					sa--;
					if(x[i].id2==2)
					{
						sb++;
						ans+=x[i].e;
					}
					else
					{
						sc++;
						ans+=x[i].e;
					}
				}
				else ans+=x[i].d;
			}
			if(x[i].id1==2)
			{
				sb++;
				if(sb>op)
				{
					sb--;
					if(x[i].id2==1)
					{
						sa++;
						ans+=x[i].e;
					}
					else
					{
						sc++;
						ans+=x[i].e;
					}
				}
				else ans+=x[i].d;
			}
			if(x[i].id1==3)
			{
				sc++;
				if(sc>op)
				{
					sc--;
					if(x[i].id2==1)
					{
						sa++;
						ans+=x[i].e;
					}
					else
					{
						sb++;
						ans+=x[i].e;
					}
				}
				else ans+=x[i].d;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
