#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],c[100100];
struct pp{int a,b;}d[100100],e[100100];
bool cmp(pp l,pp r)
{
	return l.a<r.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,i,ans;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		ans=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			ans+=a[i];
			d[i].a=a[i]-b[i];
			d[i].b=i;
		}
		sort(d+1,d+1+n,cmp);
		for(i=1;i<=n/2;i++) ans-=d[i].a,a[d[i].b]=b[d[i].b];
		for(i=1;i<=n;i++) e[i].a=a[i]-c[i],e[i].b=i;
		sort(e+1,e+1+n,cmp);
		for(i=1;i<=n/2;i++)
		{
			if(e[i].a>=0) break;
			ans-=e[i].a;
		}
		cout<<ans<<endl;
	}
	return 0;
}
