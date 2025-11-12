#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct cl
{
	int a,b,c;
};
cl p[N];
int m;
int z[N];
int e[N];
bool cmp(cl l,cl k)
{
	if(l.a<k.a) return l.a>k.a;
	if(l.a==k.a)
	{
		if(l.b<k.b) return l.b>k.b;
		
		if(l.b==k.b)
		{
			if(l.c<k.c)return l.c>k.c;
			return l.c<k.c;
		}
		return l.b<k.b;
	}
	
}
int main()
{	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	while(m)
	{
		int n,s=0,o=1,f=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		/*
		if(n==2)
		{
			int z[1]=p[1].a+p[2].a;
			int z[2]=p[1].a+p[2].b;
			int z[3]=p[1].a+p[2].c;
			int z[4]=p[1].b+p[2].a;
			int z[5]=p[1].b+p[2].b;
			int z[6]=p[1].b+p[2].c;
			int z[7]=p[1].c+p[2].a;
			int z[8]=p[1].c+p[2].b;
			int z[9]=p[1].c+p[2].c;
			sort(z+1,z+1+9);
			cout<<z[9]<<endl;
		}
		*/
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(p[i].b==p[i].c&&p[i].b==0)
			{
				f=0;
			}
			else f=1;
		}
		
		for(int i=1;i<=n;i++)
		{
			//cout<<p[i].a<<" "<<p[i].b<<" "<<p[i].c<<endl;
			if(o<=n/2)
			{
				s+=p[i].a;
				o++;
			}
		}
		if(!f)
		{
			cout<<s<<endl;
			m--;
			continue;
		}
		for(int i=o+1;i<=n;i++)
		{
			s+=p[i].b;
		}
		cout<<s<<endl;
		m--;
	}
}
