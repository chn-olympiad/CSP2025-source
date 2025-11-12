#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5; 
int t;
int n;
int a[N],b[N],c[N];
int f,f1;
int ans;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		ans=0;
		f=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1)
			{
				f=1;
			}
			if(c[i]==1)
			{
				f1=1;
			}
		}
		if(!f1)
		{
			if(!f)
			{
				for(int i=1;i<=n/2;i++)
				{
					ans+=a[i];
				} 
			}
			else
			{
				for(int i=1;i<=n/2;i++)
				{
					ans+=a[i];
				} 
				for(int i=1;i<=n/2;i++)
				{
					ans+=b[i];
				} 
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

