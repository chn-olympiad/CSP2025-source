#include<bits/stdc++.h>
#define int long long
using namespace std;
const int BIG=1e6;
struct ff{
	int a,b,c,cha;
}a[BIG];
int T,n,ans,b[10];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=b[1]=b[2]=b[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c)a[i].cha=a[i].a-max(a[i].b,a[i].c);
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)a[i].cha=a[i].b-max(a[i].a,a[i].c);
			else a[i].cha=a[i].c-max(a[i].a,a[i].b);
		}
		sort(a+1,a+1+n,[](ff x,ff y){return x.cha>y.cha;});
		for(int i=1;i<=n;i++)
		{
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
			{
				if(b[1]<n/2)b[1]++,ans+=a[i].a;
				else if(a[i].b>a[i].c&&b[2]<n/2)b[2]++,ans+=a[i].b;
				else b[3]++,ans+=a[i].c;
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
			{
				if(b[2]<n/2)b[2]++,ans+=a[i].b;
				else if(a[i].a>a[i].c&&b[1]<n/2)b[1]++,ans+=a[i].a;
				else b[3]++,ans+=a[i].c;
			}
			else
			{
				if(b[3]<n/2)b[3]++,ans+=a[i].c;
				else if(a[i].b>a[i].a&&b[2]<n/2)b[2]++,ans+=a[i].b;
				else b[1]++,ans+=a[i].a;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
