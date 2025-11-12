#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,ans,t1;
bool f[500005];
struct pr
{
	int l,r;
	pr(int _l,int _r)
	{
		l=_l;r=_r;
	}
};
vector<pr> b;
void num(int x)
{
	int t=0;
	for(int i=x;i<n;i++)
	{
		t^=a[i];
		if(t==k)
		{
			b.push_back(pr(x,i));			
		}
	}
}
bool check(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		if(f[i]==1)
		{
			return 0;
		}
	}
	return 1;
}
void dfs(int k,int t)
{
	if(k==b.size())
	{
		ans=max(ans,t);
		return;
	}
	if(check(b[k].l,b[k].r))
	{
		for(int i=b[k].l;i<=b[k].r;i++)
		{
			f[i]=1;
		}
		dfs(k+1,t+1);
		for(int i=b[k].l;i<=b[k].r;i++)
		{
			f[i]=0;
		}
	}
	dfs(k+1,t);

}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		num(i);
	}
	dfs(0,0);
	cout<<ans; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
