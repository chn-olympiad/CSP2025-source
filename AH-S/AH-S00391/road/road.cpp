#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+5,M=1e6+5;
struct node
{
	int s;
	int t;
	int va;
}a[M];
bool cmp(node u,node v)
{
	return u.va < v.va;
}
int fa[N];
int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	priority_queue<int> q;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i = 1;i<=m;i++)
	{
		cin >> a[i].s >> a[i].t >> a[i].va;
	}
	sort(a+1,a+1+n,cmp);
	int num=n;
	int ta,tb;
	long long  ans=0;
	int tmp=1;
	while(num!=1)
	{
		/*
		for(int i =1 ;i<=n;i++)
		{
			cout << fa[i] << " ";
		}
		cout << "\n";
		* */
		ta=find(fa[a[tmp].s]);
		tb=find(fa[a[tmp].t]);
		if(ta!=tb)
		{
			num--;
			fa[ta]=tb;
			ans+=a[tmp].va;
		}
		tmp++;
	}
	cout << ans;
	return 0;
}
