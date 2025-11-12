#include<bits/stdc++.h>
using namespace std;
long long sum=0,n,k;
struct we
{
	long long a,b,c;
}v[100005];
bool cmp1(we x,we y)
{
	return x.a>y.a;
}
void dfs(int xb,int x,long long xz,int y,long long yz,int z,long long zz)
{
	if(x>k||y>k||z>k)return;
	if(xb>n)
	{
		sum=max(sum,xz+yz+zz);
		return;
	}
	dfs(xb+1,x+1,xz+v[xb].a ,y,yz,z,zz);
	dfs(xb+1,x,xz ,y+1,yz+v[xb].b,z,zz);
	dfs(xb+1,x,xz ,y,yz,z+1,zz+v[xb].c);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		sum=0;
		cin>>n;
		k=n/2;
		int p=0,q=0;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i].a>>v[i].b>>v[i].c;
			if(v[i].b!=0)p++;
			if(v[i].c!=0)q++;
		}
		if(p==0&&q==0)
		{
			sort(v,v+n+1,cmp1);
			long long ans=0;
			for(int i=0;i<k;i++)
			{
				ans+=v[i].a;
			}
			cout<<ans;
			continue;
		}
		dfs(0,0,0,0,0,0,0);
		cout<<sum<<endl;
	}
	return 0;
}
