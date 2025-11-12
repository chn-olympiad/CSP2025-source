#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}p[500100];
int n,k,ans,tt;
int a[500100],q[500100];
vector<int> v[1100000];
bool cmp(node xx,node yy)
{
	if(xx.y!=yy.y)
	{
		return xx.y<yy.y;
	}
	if(xx.x!=yy.x)
	{
		return xx.x>yy.x;
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		q[i]=q[i-1]^a[i];
		v[q[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		p[i].x=i;
		if(a[i]==k)
		{
			p[i].y=i;
			continue;
		}
		int t=q[i-1]^k;
		if(!v[t].size())
		{
			p[i].y=n+1;
			continue;
		}
		int pp=lower_bound(v[t].begin(),v[t].end(),i)-v[t].begin();
		if(pp==v[t].size())
		{
			p[i].y=n+1;
		}
		else
		{
			p[i].y=v[t][pp];
		}
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(p[i].y>n)
		{
			continue;
		}
		if(p[i].x>tt)
		{
			tt=p[i].y;
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
