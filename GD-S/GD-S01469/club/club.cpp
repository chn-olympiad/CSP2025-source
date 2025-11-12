#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct p{
	int v[5];
};
int t;
int anum[5];
int n,ans;
p a[N];
bool cmp(p a,p b)
{
	return a.v[1]>b.v[1];
}
void dfs(int dep,int d,int pian)
{
	for(int i=1;i<=pian;i++)
	{
		if(anum[i]+1 > n/2) continue;
		anum[i]++;
		d+=a[dep].v[i];
		if(dep==n)
		{
			ans=max(ans,d);
			d-=a[dep].v[i];
			anum[i]--;
			continue;
		}
		else 
		{
			dfs(dep+1,d,pian);
		}
		d-=a[dep].v[i];
		anum[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].v[1]>>a[i].v[2]>>a[i].v[3];
		}
		bool flag3=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i].v[3]!=0)
			{
				flag3=0;
				break;
			}
		}
		if(flag3)
		{
			bool flag2=1;
			for(int i=1;i<=n;i++)
			{
				if(a[i].v[2]!=0)
				{
					flag2=0;
					break;
				}
			}
			if(flag2)
			{
				sort(a+1,a+1+n,cmp);
				for(int i=1;i<=n/2;i++) ans+=a[i].v[1];
			}
			else
			{
				dfs(1,0,2);
			}
		}
		else dfs(1,0,3);
		cout<<ans<<'\n'; 
		ans=0;
		for(int i=1;i<=3;i++) anum[i]=0;
	}
	return 0;
}
