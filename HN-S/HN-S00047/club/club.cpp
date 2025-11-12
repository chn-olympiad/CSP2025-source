#include <bits/stdc++.h>
using namespace std;
struct c{
	int x,y,z;
}a[100005];
int T,n,b[100005];
bool A;
bool cmp1(c e,c f)
{
	return e.x>f.x;
}
long long f(int k,int p,int q,int r)
{
	if(p>n/2||q>n/2||r>n/2)
		return 0;
	if(k>n)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0)
				ans+=a[i].x;
			if(b[i]==1)
				ans+=a[i].y;
			if(b[i]==2)
				ans+=a[i].z;
		}
		return ans;
	}
	long long ans=0;
	b[k]=0;
	ans=max(ans,f(k+1,p+1,q,r));
	b[k]=1;
	ans=max(ans,f(k+1,p,q+1,r));
	b[k]=2;
	ans=max(ans,f(k+1,p,q,r+1));
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		A=true;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			A&=(a[i].y==0&&a[i].z==0);
		}
		if(A)
		{
			sort(a+1,a+n+1,cmp1);
			long long ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			cout<<ans<<'\n';
		}
		else
			cout<<f(1,0,0,0)<<'\n';
	}
	return 0;
}
