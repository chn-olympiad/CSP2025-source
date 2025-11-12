#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100000;
int opt,n,b1,c1,a1,ans,w;
struct tt
{
	int first,second;
};
tt b[2*N+5],c[2*N+5],f[2*N+5];
bool cmp(tt a,tt b)
{
	return min(a.first,a.second)<min(b.first,b.second);
}
struct ttp
{
	int a,b,c;
}a[N+5]; 
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>opt;
	while(opt--)
	{
		long long ans=0;
		b1=0,c1=0,a1=0,w=0;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			long long maxx=0,k=0,p=0;
			cin>>a[i].a>>a[i].b>>a[i].c;
			p=max(a[i].a,max(a[i].b,a[i].c));
			if(p==a[i].a)
			{
				ans+=a[i].a;
				f[++a1].first=a[i].a-a[i].b;
				f[a1].second=a[i].a-a[i].c;
			}
			else if(p==a[i].b)
			{
				ans+=a[i].b;
				b[++b1].first=a[i].b-a[i].a;
				b[b1].second=a[i].b-a[i].c;
			}
			else if(p==a[i].c)
			{
				ans+=a[i].c;
				c[++c1].first=a[i].c-a[i].a;
				c[c1].second=a[i].c-a[i].b;
			}
		}
		sort(f+1,f+1+a1,cmp);
		sort(b+1,b+1+b1,cmp);
		sort(c+1,c+1+c1,cmp);
		if(a1>n/2)
		{
			int d=0;
			while(a1>n/2)
			{
				
				d++;
				if(f[d].first==0&&f[d].second==0) continue;
				ans-=min(f[d].first,f[d].second);
				f[d].first=0,f[d].second=0;
				a1--;
				if(b1>c1)
				{
					c1++;
				}
				else b1++;
			}
		}
		if(b1>n/2)
		{
			int d=0;
			while(b1>n/2)
			{
				
				d++;
				if(b[d].first==0&&b[d].second==0) continue;
				ans-=min(b[d].first,b[d].second);
				b[d].first=0,b[d].second=0;
				b1--;
				if(a1>c1)
				{
					c1++;
				}
				else a1++;
			}
		}
		if(c1>n/2)
		{
			int d=0;
			while(c1>n/2)
			{
				
				d++;
				if(c[d].first==0&&c[d].second==0) continue;
				ans-=min(c[d].first,c[d].second);
				c[d].first=0,c[d].second=0;
				c1--;
				if(a1>b1)
				{
					b1++;
				}
				else a1++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}



