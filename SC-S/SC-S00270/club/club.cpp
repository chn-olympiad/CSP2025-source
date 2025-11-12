#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
const int maxn=1e5+10;
int t;
int n;
struct people
{
	int a,b,c;
} q[maxn];
int ans[maxn],cha[maxn];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		memset(cha,0x3f,sizeof(cha));
		n=read();
		for(int i=1;i<=n;i++) q[i]={read(),read(),read()};
		int cnta=0,cntb=0,cntc=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(q[i].a>=q[i].b&&q[i].a>=q[i].c) cnta++,ans[i]=q[i].a;
			else if(q[i].b>=q[i].a&&q[i].b>=q[i].c) cntb++,ans[i]=q[i].b;
			else if(q[i].c>=q[i].a&&q[i].c>=q[i].b) cntc++,ans[i]=q[i].c;
			sum+=ans[i];
		}
		if(cnta>n/2)
		{
			for(int i=1;i<=n;i++) if(ans[i]==q[i].a) cha[i]=min(ans[i]-q[i].b,ans[i]-q[i].c);
			sort(cha+1,cha+1+n);
			for(int i=1;i<=cnta-n/2;i++) sum-=cha[i];
		}
		else if(cntb>n/2)
		{
			for(int i=1;i<=n;i++) if(ans[i]==q[i].b) cha[i]=min(ans[i]-q[i].a,ans[i]-q[i].c);
			sort(cha+1,cha+1+n);
			for(int i=1;i<=cntb-n/2;i++) sum-=cha[i];
		}
		else if(cntc>n/2)
		{
			for(int i=1;i<=n;i++) if(ans[i]==q[i].c) cha[i]=min(ans[i]-q[i].b,ans[i]-q[i].a);
			sort(cha+1,cha+1+n);
			for(int i=1;i<=cntc-n/2;i++) sum-=cha[i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}
//rp++ 
//finish 15:09