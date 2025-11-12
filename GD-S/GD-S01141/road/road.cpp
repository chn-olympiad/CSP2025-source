#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[15][10005],c[15],bz[15],ans,f[10005],cnt,cnt2,ans2;
struct www{
	long long u,v,w;
}e[1000005];
struct sss{
	long long u,v,w;
}s[200005],s2[200005];
bool cmp(www x,www y)
{
	return x.w<y.w;
}
bool cmp2(sss x,sss y)
{
	return x.w<y.w;
}
int find(int l)
{
	if(l==f[l])
		return l;
	return f[l]=find(f[l]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int xx=find(e[i].u);
		int yy=find(e[i].v);
		if(xx!=yy)
		{
			f[xx]=yy;
			ans+=e[i].w;
			cnt++;
			s[cnt].u=e[i].u;
			s[cnt].v=e[i].v;
			s[cnt].w=e[i].w;
		}
	}
	for(int i=1;i<=(1<<k)-1;i++)
	{
		cnt2=cnt;
		for(int j=1;j<=cnt;j++)
		{
			s2[j].u=s[j].u;
			s2[j].v=s[j].v;
			s2[j].w=s[j].w;
		}
		int ee=i,ss=1,tt=0;
		ans2=0;
		while(ee)
		{
			if(ee%2==1)
			{
				ans2+=c[ss];
				if(ans2>=ans)
				{
					break;
				}
				for(int j=1;j<=n;j++)
				{
					cnt2++;
					s2[cnt2].u=ss+n;
					s2[cnt2].v=j;
					s2[cnt2].w=a[ss][j];
				}
				tt++;
			}
			ee/=2;
			ss++;
		}
		if(ans2>=ans)
		{
			continue;
		}
//		cout<<cnt2<<endl;
		sort(s2+1,s2+cnt2+1,cmp2);
//		for(int j=1;j<=cnt2;j++)
//			cout<<s2[j].u<<" "<<s2[j].v<<" "<<s2[j].w<<endl;
//		cout<<endl;
		for(int j=1;j<=n+k;j++)
		{
			f[j]=j;
		}
		for(int j=1;j<=cnt2;j++)
		{
			int xx=find(s2[j].u);
			int yy=find(s2[j].v);
			if(xx!=yy)
			{
				ans2+=s2[j].w;
				f[xx]=yy;
				if(ans2>=ans)
				{
					break;
				}
			}
		}
		ans=min(ans,ans2);
	}
	cout<<ans;
}
