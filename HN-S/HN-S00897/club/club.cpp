#include<bits/stdc++.h>
using namespace std;
int t,n,x[100010],y[100010],z[100010],ax,ay,az;
long long ans;
struct c
{
	int a,b,d;
}e[100010];
bool cmp(c h,c l)
{
	return h.d>l.d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		ax=0,ay=0,az=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i]>>z[i];
			if(x[i]>max(y[i],z[i]))ax++;
			else if(y[i]>z[i])ay++;
			else az++;
			ans+=max(x[i],max(y[i],z[i]));
		}
		if(ax<=n/2&&ay<=n/2&&az<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(ax>n/2)
			e[i].a=x[i],e[i].b=max(y[i],z[i]);
			else if(ay>n/2)
			e[i].a=y[i],e[i].b=max(x[i],z[i]);
			else
			e[i].a=z[i],e[i].b=max(x[i],y[i]);
			e[i].d=e[i].a-e[i].b;
		}
		sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(i<=n/2)ans+=e[i].a;
			else ans+=e[i].b;
		}
		cout<<ans<<endl;
	}
	return 0;
}
