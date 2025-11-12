#include<bits/stdc++.h>
using namespace std;
const int mod=1e7+7;
struct qq{int x,max1;};
vector<qq> xo[mod+5];
int n,k;
int a[500005];
int f[500005];
void insert(int x,int mmax)
{
	int q=x%mod;
	int si=xo[q].size();
	for(int i=0;i<si;i++)
	{
		if(xo[q][i].x==x)
		{
			xo[q][i].max1=max(xo[q][i].max1,mmax);
			return;
		}
	}
	xo[q].push_back({x,mmax}); 
}
int query(int x)
{
	int q=x%mod;
	int si=xo[q].size();
	for(int i=0;i<si;i++)
	{
		if(xo[q][i].x==x) return xo[q][i].max1;
	}
	return -1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int y=0;
	insert(0,0);
	for(int i=1;i<=n;i++)
	{
		y^=a[i];
		f[i]=max(f[i-1],query(y^k)+1);
		insert(y,f[i]);
	}
	cout<<f[n];
}
