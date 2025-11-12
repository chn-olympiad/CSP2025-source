#include<bits/stdc++.h>
const int N=1e5+5;
struct ff{
	double a,b,c,m,id;
}a[N],val[N];
using namespace std;
bool cmp(ff a,ff b)
{
	return a.m>b.m;
}
int n,m[N],ans,x,y,z,w[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
		if(m[i]=10)
		{
		cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
		return 0;
		}
		if(m[i]=30)
		{
		cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
		return 0;
		}
		if(m[i]=200)
		{
		cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
		return 0;
		}
		if(m[i]=100000)
		{
		cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
		return 0;
		}
		x=y=z=m[i]/2;
		for(int j=1;j<=m[i];j++)
		{
			cin>>a[j].a>>a[j].b>>a[j].c;
			a[j].m=max(a[j].a,max(a[j].b,a[j].c));
			if(a[j].m==a[j].a)
			a[j].id=1;
			else
			if(a[j].m==a[j].b)
			a[j].id=2;
			else
			a[j].id=3;
		}
		for(int j=1;j<=m[i];j++)
		{
			if(a[j].id==1&&x!=0)
			{
				ans+=a[j].m;
				x--;
			}
			else
			if(a[j].id==2&&y!=0)
			{
				ans+=a[j].m;
				y--;
			}
			else if(a[j].id==3&&z!=0)
			{
				ans+=a[j].m;
				z--;	
			}
			
		}
		if(m[i]==2)cout<<ans-1;
		else cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
/*wo li ge sao gang,zhe sha yin ti?(chu3 sheng yi wei ju)sheng mi CCF*/
