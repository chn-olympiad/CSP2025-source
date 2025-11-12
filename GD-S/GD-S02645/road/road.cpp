#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,t,ans,f[1000005];
struct node
{
	int u,v,x;
}a[1000005];
bool cmp(node x,node y)
{
	return x.x<y.x;
}
unordered_set<int> st;
int find(int x)
{
	if(f[x]!=x) 
	{
		f[x]=find(x);
		return f[x];
	}
	return f[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].x;
		f[i]=i;
	}
	sort(a+1,a+1+m,cmp);
	int it=1;
	while(st.size()<n)
	{
		if(find(a[it].u)!=find(a[it].v))
		{
			st.insert(a[it].v);
			st.insert(a[it].u);
			ans+=a[it].x;
			f[find(a[it].u)]=f[find(a[it].v)];
		}
		it++;
	}
	cout<<ans;
	return 0;
}


