#include<bits/stdc++.h>
using namespace std;
long long t,n,sa,sb,sc,sum,g,l;
struct club
{
	int a,b,c,ma,ss,k;
}x[100010];
bool cmp(club x,club y)
{
	if(x.k==y.k) return x.ss<y.ss;
	return x.k<y.k;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;sa=sb=sc=sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i].a>>x[i].b>>x[i].c;
			x[i].ma=max(max(x[i].a,x[i].b),x[i].c);
			sum+=x[i].ma;
		
			if(x[i].a==x[i].ma) x[i].ss=x[i].a-max(x[i].b,x[i].c);
			else if(x[i].b==x[i].ma) x[i].ss=x[i].b-max(x[i].a,x[i].c);
			else if(x[i].c==x[i].ma) x[i].ss=x[i].c-max(x[i].a,x[i].b);
			
			if(x[i].a>=x[i].b&&x[i].a>=x[i].c) sa++,x[i].k=1;
			else if(x[i].b>x[i].a&&x[i].b>=x[i].c) sb++,x[i].k=2;
			else if(x[i].c>x[i].a&&x[i].c>x[i].b) sc++,x[i].k=3;
		}
		if(sa<=n/2&&sb<=n/2&&sc<=n/2) cout<<sum<<"\n";
		else
		{
			if(sa>n/2) g=1,l=sa-n/2;
			if(sb>n/2) g=2,l=sb-n/2;
			if(sc>n/2) g=3,l=sc-n/2;
			sort(x+1,x+1+n,cmp);
			for(int i=1;i<=n;i++)
			{
				if(l==0) break;
				if(x[i].k==g&&l>0) sum-=x[i].ss,l--;
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
} 

