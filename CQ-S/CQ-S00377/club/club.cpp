#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int e1,e2,e3,d1,d2,d3,d;
	bool f;
}a[N];

bool cmp1(node a,node b){return a.d1>b.d1;}
bool cmp2(node a,node b){return a.d2>b.d2;}
bool cmp3(node a,node b){return a.d3>b.d3;}
bool cmp (node a,node b){return a.d>b.d;}
void solve()
{
	
	int n;
	long long ans=0;
	scanf("%d",&n);
	int v1=n/2,v2=n/2,v3=n/2;
	for(int i=1;i<=n;i++)
		a[i].f=0;
	
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].e1,&a[i].e2,&a[i].e3);
		
	for(int i=1;i<=n;i++) 
		a[i].d1=a[i].e1-max(a[i].e2,a[i].e3),
		a[i].d2=a[i].e2-max(a[i].e1,a[i].e3),
		a[i].d3=a[i].e3-max(a[i].e1,a[i].e2);
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++)
		if(a[i].f==0)
		{
			if(a[i].d1>=0 and v1>0)
			{
				v1--;
				a[i].f=1;
				ans+=a[i].e1;
			}
			else
				break;
		}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++)
		if(a[i].f==0)
		{
			if(a[i].d2>=0 and v2>0)
			{
				a[i].f=1;
				v2--;
				ans+=a[i].e2;
			}
			else
				break;
		}
	sort(a+1,a+n+1,cmp3);
	for(int i=1;i<=n;i++)
		if(a[i].f==0)
		{
			if(a[i].d3>=0 and v3>0)
			{
				a[i].f=1;
				v3--;
				ans+=a[i].e3;
			}
			else
				break;
		}
	if(v1==0)
	{
		for(int i=1;i<=n;i++)
			a[i].d=a[i].d2-a[i].d3;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
			if(a[i].f==0)
			{
				if((v3==0) or (a[i].d>=0 and v2>0))
				{
					v2--;
					ans+=a[i].e2;
				}
				else
				{
					v3--;
					ans+=a[i].e3;
				}
			}
	}
	else if(v2==0)
	{
		for(int i=1;i<=n;i++)
			a[i].d=a[i].d1-a[i].d3;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
			if(a[i].f==0)
			{
				if((v3==0) or (a[i].d>=0 and v1>0))
				{
					v1--;
					ans+=a[i].e1;
				}
				else
				{
					v3--;
					ans+=a[i].e3;
				}
			}
	}
	else
	{
		for(int i=1;i<=n;i++)
			a[i].d=a[i].d1-a[i].d2;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
			if(a[i].f==0)
			{
				if((v2==0) or (a[i].d>=0 and v1>0))
				{
					v1--;
					ans+=a[i].e1;
				}
				else
				{
					v2--;
					ans+=a[i].e2;
				}
			}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
