#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans=0;
int a[200010],b[200010],c[200010];
int aj,bj,cj;
int ai,bi,ci;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		ans=0;
		aj=0,bj=0,cj=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>ai>>bi>>ci;
			if(ai==max(ai,max(bi,ci)))
			{
				a[++aj]=ai-max(bi,ci);
				ans+=ai;
			}
			else if(bi==max(ai,max(bi,ci)))
			{
				b[++bj]=bi-max(ai,ci);
				ans+=bi;
			}
			else
			{
				c[++cj]=ci-max(ai,bi);
				ans+=ci;
			}
		}
		if(aj>n/2)
		{
			sort(a+1,a+1+aj);
			for(int i=1;i<=aj-n/2;i++)
			{
				ans-=a[i];			
			}
		}
		else if(bj>n/2)
		{
			sort(b+1,b+1+bj);
			for(int i=1;i<=bj-n/2;i++)
			{
				ans-=b[i];			
			}
		}
		else if(cj>n/2)
		{
			sort(c+1,c+1+cj);
			for(int i=1;i<=cj-n/2;i++)
			{
				ans-=c[i];			
			}
		}
		cout<<ans<<'\n';
	}
}
