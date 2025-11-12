#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,n,ans,o[5];

struct asdf
{
	int a[3],b[3];
}s[101010],e[101010];

int cmp(asdf x,asdf y)
{
	if(x.a[1]==y.a[1])return x.b[1]>y.b[1];
	return x.a[1]>y.a[1];
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		cin>>n;int x,y,z;ans=0;memset(o,0,sizeof o);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			if(x>=y&&y>=z)
			{
				s[i].a[1]=x;
				s[i].b[1]=y;
				s[i].a[0]=1;
				s[i].b[0]=2;
			}
			else if(x>=z&&z>=y)
			{
				s[i].a[1]=x;
				s[i].b[1]=z;
				s[i].a[0]=1;
				s[i].b[0]=3;
			}
			else if(y>=x&&x>=z)
			{
				s[i].a[1]=y;
				s[i].b[1]=x;
				s[i].a[0]=2;
				s[i].b[0]=1;
			}
			else if(y>=z&&z>=x)
			{
				s[i].a[1]=y;
				s[i].b[1]=z;
				s[i].a[0]=2;
				s[i].b[0]=3;
			}
			else if(z>=x&&x>=y)
			{
				s[i].a[1]=z;
				s[i].b[1]=x;
				s[i].a[0]=3;
				s[i].b[0]=1;
			}
			else if(z>=y&&y>=x)
			{
				s[i].a[1]=z;
				s[i].b[1]=y;
				s[i].a[0]=3;
				s[i].b[0]=2;
			}
			o[s[i].a[0]]++;
		}
		sort(s+1,s+n+1,cmp);
		int oo,ox;
		if(max(o[1],max(o[2],o[3]))==o[2])oo=o[2],ox=2;
		if(max(o[1],max(o[2],o[3]))==o[1])oo=o[1],ox=1;
		if(max(o[1],max(o[2],o[3]))==o[3])oo=o[3],ox=3;
		if(oo<=n/2)
		{
			for(int i=1;i<=n;i++)ans+=s[i].a[1];
		}
		else
		{
			int tot=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i].a[0]==ox)e[++tot]=s[i];
				else ans+=s[i].a[1];
			}
			sort(e+1,e+tot+1,cmp);
			int w[101010];
			for(int i=1;i<=tot;i++)w[i]=e[i].a[1]-e[i].b[1],ans+=e[i].a[1];
			sort(w+1,w+tot+1);
			for(int i=1;i<=tot-n/2;i++)ans-=w[i];
//			for(int i=1;i<=tot;i++)cout<<e[i].a[1]<<" "<<e[i].b[1]<<" "<<e[i].a[0]<<" "<<e[i].b[0]<<endl;
//			cout<<tot;
		}
		cout<<ans<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
