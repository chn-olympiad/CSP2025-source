#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],maxn=0;
bool v[500001];
int yihuo(int a,int b)
{
	bool x[31],y[31],z[31];
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(z,0,sizeof(z));
	int s=0,t=0;
	while(a!=0) x[++s]=a%2,a/=2;
	while(b!=0) y[++t]=b%2,b/=2;
	for(int i=1;i<=max(s,t);i++)
	{
		if(x[i]!=y[i]) z[i]=1;
		else z[i]=0;
	}
	int ans=0,q=1;
	for(int i=1;i<=max(s,t);i++)
	{
		if(z[i]) ans+=q;
		q*=2;
	}
	return ans;
}
void dfs(int ans)
{
	bool you=0;
	for(int l=1;l<=n;l++)
	{
		if(v[l]) continue;
		int x=0;
		for(int r=l;r<=n;r++)
		{
			if(v[r]) break;
			x=yihuo(x,a[r]);
			if(x==k)
			{
				you=1;
				for(int i=l;i<=r;i++) v[i]=1;
				dfs(ans+1);
				for(int i=l;i<=r;i++) v[i]=0;
			}
		}
	}
	if(!you&&ans>maxn) maxn=ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0);
	cout<<maxn;
	return 0;
}
