#include<bits/stdc++.h>
using namespace std;
int cnt[4],n;
long long ans=0;
struct node{
	int a,b,c,vis,mx,it;
}phi[100005];
void maxx(node& p)
{
	if(p.a>=p.b&&p.a>=p.c)
		{
			p.mx=p.a;
			p.it=1;
		}
		else if(p.b>=p.c)
		{
			p.mx=p.b;
			p.it=2;
		}
		else
		{
			p.mx=p.c;
			p.it=3;
		}
}
bool cmp(const node& p,const node& q)
{
	if(p.vis<q.vis) return true;
	else return p.mx>q.mx;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>phi[i].a>>phi[i].b>>phi[i].c;
		phi[i].vis=0;
		maxx(phi[i]);
	}
	sort(phi,phi+n,cmp);
	for(int i=0;n>0;++i)
	{
		if(cnt[1]==n/2)
		{
			for(int j=i;j<n;++j)
			{
				phi[j].a=0;
				maxx(phi[j]);
				sort(phi,phi+n,cmp);
			}
		}
		if(cnt[2]==n/2)
		{
			for(int j=i;j<n;++j)
			{
				phi[j].b=0;
				maxx(phi[j]);
				sort(phi,phi+n,cmp);
			}
		}
		if(cnt[3]==n/2)
		{
			for(int j=i;j<n;++j)
			{
				phi[j].c=0;
				maxx(phi[j]);
				sort(phi,phi+n,cmp);
			}
		}
		ans+=phi[i].mx;
		phi[i].vis=1;
		cnt[phi[i].it]++;
		n--;
	}
	cout<<ans<<"\n";
	return 0;
}
