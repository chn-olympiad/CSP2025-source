#include<bits/stdc++.h>

using namespace std;

struct node
{
	int id;
	int a1;
	int a2;
	int a3;
	int maxn;
	int maxn_id;
}a[100001];
int t,n;
long long ans;
bool state1=1,state2=1;

bool cmp(node a,node b)
{
	return a.a1>b.a1;
}
bool cmp1(node a,node b)
{
	return a.maxn>b.maxn;
}

void dfs(int c1,int c2,int c3,int id,long long sum)
{
	//cout << "#" << c1 << " " << c2 << " " << c3 << " " << id << " " << sum << endl;
	if(id>n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1&&c1>=n/2)
			continue;
		if(i==2&&c2>=n/2)
			continue;
		if(i==3&&c3>=n/2)
			continue;
		if(i==1)
			dfs(c1+1,c2,c3,id+1,sum+a[id].a1);
		if(i==2)
			dfs(c1,c2+1,c3,id+1,sum+a[id].a2);
		if(i==3)
			dfs(c1,c2,c3+1,id+1,sum+a[id].a3);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			a[i].id=i;
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3)
			{
				a[i].maxn=a[i].a1;
				a[i].maxn_id=1;
			}
			else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3)
			{
				a[i].maxn=a[i].a2;
				a[i].maxn_id=2;
			}
			else
			{
				a[i].maxn=a[i].a3;
				a[i].maxn_id=3;
			}
			if(a[i].a2!=0||a[i].a3!=0)
			{
				state1=0;
			}
			if(a[i].a3!=0)
			{
				state2=0;
			}
		}
		if(state1)
		{
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++)
				{
					ans += a[i].a1;
				}
				cout << ans;
				ans=0;
				continue;
		}
		dfs(0,0,0,1,0);
		cout << ans << endl;
		ans=0;
	}
	return 0;
}
