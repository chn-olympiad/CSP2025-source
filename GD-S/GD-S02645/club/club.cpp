#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,ans;
struct com
{
	ll v;
	int x; 
};
struct node
{
	com t[3];
}a[100005];
bool cmp1(com x,com y)
{
	return x.v>y.v;
}
bool cmp2(node x,node y)
{
	return (x.t[0].v+y.t[1].v)>(y.t[0].v+x.t[1].v);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<node> vt[3];
		bool flag=true;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].t[0].v>>a[i].t[1].v>>a[i].t[2].v;
			a[i].t[0].x=0,a[i].t[1].x=1,a[i].t[2].x=2;
			sort(a[i].t,a[i].t+3,cmp1);
			vt[a[i].t[0].x].push_back(a[i]);
		}
		for(int i=0;i<3;i++)
		{
			if(vt[i].size()>n/2&&flag)
			{	
				sort(vt[i].begin(),vt[i].end(),cmp2);
				for(int j=vt[i].size()-1;j>(n/2-1);j--)
				{
					node tmp=vt[i][j];
					vt[i][j]={{0,0,0}};
					vt[tmp.t[1].x].push_back({tmp.t[1].v,0,0});
				}
				flag=false;
			}
			for(int j=0;j<vt[i].size();j++)
			{
				ans+=vt[i][j].t[0].v;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


