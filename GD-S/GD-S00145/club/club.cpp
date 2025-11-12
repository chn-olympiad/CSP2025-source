#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,l[5],ans;
struct W 
{
	long long a1,b1,c1,f,n,o,it;
}w[300010];
bool cmp(W x,W y)
{
	return x.n>y.n;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>a;
for(int i=1;i<=a;i++)	
	{
		cin>>b;
		for(int j=1;j<=b;j++)
		{
			cin>>w[j].a1>>w[j].b1>>w[j].c1;
			d=max(w[j].a1,max(w[j].b1,w[j].c1));
			e=min(w[j].a1,min(w[j].b1,w[j].c1));
			w[j].f=d;
			w[j].n=d-(w[j].a1+w[j].b1+w[j].c1-d-e);
			w[j].o=w[j].a1+w[j].b1+w[j].c1-d-e;
			if(d==w[j].a1)
			{
				w[j].it=1;
				
			}
				if(d==w[j].b1)
			{
				w[j].it=2;
				
			}
				if(d==w[j].c1)
			{
				w[j].it=3;
				
			}
		}
		sort(w+1,w+b+1,cmp);
		e=b/2;
		for(int j=1;j<=b;j++)
		{
			l[w[j].it]++;
			if(l[w[j].it]<=e)
			{
				ans+=w[j].f;
			}
			else
			{
				ans+=w[j].o;
			}
		}
		l[1]=0;
		l[2]=0;
		l[3]=0;
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
 } 
