#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r;
};
bool cmp(node a,node b)
{
	return (a.r-a.l)<(b.r-b.l);
}
int n,k,a[1005],ans,vis[1005];
vector<node> v;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)	v.push_back({i,i});
		int sum=a[i];
		for(int j=i+1;j<=n;j++)
		{
			sum=sum^a[j];
			if(sum==k)	v.push_back({i,j});
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(auto p:v)
	{
		int sum=0;
		for(int i=p.l;i<=p.r;i++)	sum+=vis[i];
		if(sum==0)
		{
			for(int i=p.l;i<=p.r;i++)	vis[i]=1;
			ans++;				
		}
	}
	cout<<ans;
	return 0;
} 
