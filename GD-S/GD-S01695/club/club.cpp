#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005],d[100005],t,e,f,g;
struct fan{
	int xu,zhi;
};
fan a1[100005],b1[100005],c1[100005];
bool cm1p(const fan&x,const fan&y)
{
	return x.zhi<y.zhi;
}
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		e=0;
		f=0;
		g=0;
		ans=0;
		cin>>n;
		for (int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			d[j]=max(a[j],max(b[j],c[j]));
			if (d[j]==a[j]) 
			{
				e+=1;
				a1[e].xu=j;
			}
			else if (d[j]==b[j]) 
			{
				f+=1;
				b1[f].xu=j;
			}
			else if (d[j]==c[j]) 
			{
				g+=1;
				c1[g].xu=j;
			}
		}
		if (e>n/2)
		{
			for (int j=1;j<=e;j++)
			{
				a1[j].zhi=d[a1[j].xu]-max(b[a1[j].xu],c[a1[j].xu]);
			}
			sort (a1+1,a1+1+e,cm1p);
			for (int j=1;j<=e-n/2;j++)
			{
				ans-=a1[j].zhi;
			}
		}
		else if (f>n/2)
		{
			for (int j=1;j<=f;j++)
			{
				b1[j].zhi=d[b1[j].xu]-max(a[b1[j].xu],c[b1[j].xu]);
			}
			sort (b1+1,b1+1+f,cm1p);
			for (int j=1;j<=f-n/2;j++)
			{
				ans-=b1[j].zhi;
			}
		}
		else if (g>n/2)
		{
		
			for (int j=1;j<=g;j++)
			{
				c1[j].zhi=d[c1[j].xu]-max(b[c1[j].xu],a[c1[j].xu]);
			}
			sort (c1+1,c1+1+g,cm1p);
			for (int j=1;j<=g-n/2;j++)
			{
				ans-=c1[j].zhi;
			}
		}
		sort (d+1,d+1+n);
		for (int j=1;j<=n;j++)
		{
			ans+=d[j];
		}
		cout<<ans<<"\n";
	}
	return 0;
 } 
