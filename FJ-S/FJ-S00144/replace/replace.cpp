#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10,MAXL=5e6+10,B=131,mod=1e9+7;
int fac[MAXL];
int n,q;
struct node
{
	string s1,s2;
	int len;
	int l,r,t;
	int ha1,ha2;
} a[MAXN];
bool cmp(node x,node y)
{
	return x.t<y.t;
}
int hea[MAXL];
string t1,t2;
int hha1[MAXL],hha2[MAXL];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=5000000;i++)
		fac[i]=1ll*fac[i-1]*B%mod;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
		a[i].len=a[i].s1.length();
		for(int j=0;j<a[i].len;j++)
			if(a[i].s1[j]!=a[i].s2[j])
				{ a[i].l=j; break;}
		for(int j=a[i].len-1;j>=0;j--)
			if(a[i].s1[j]!=a[i].s2[j])
				{ a[i].r=j; break;}
		a[i].t=a[i].r-a[i].l+1;
		a[i].ha1=a[i].s1[0]-'a'+1;
		a[i].ha2=a[i].s2[0]-'a'+1;
		for(int j=1;j<a[i].len;j++)
		{
			a[i].ha1=(1ll*a[i].ha1*B%mod+a[i].s1[j]-'a'+1)%mod;
			a[i].ha2=(1ll*a[i].ha2*B%mod+a[i].s2[j]-'a'+1)%mod;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(a[i].t!=a[i-1].t)
			hea[a[i].t]=i;
	while(q--)
	{
		cin>>t1>>t2;
		int llen=t1.length(),ll=0,rr=0;
		for(int i=0;i<llen;i++)
			if(t1[i]!=t2[i]) { ll=i; break;}
		for(int i=llen-1;i>=0;i--)
			if(t1[i]!=t2[i]) { rr=i; break;}
		int tt=rr-ll+1;
		hha1[0]=0; hha1[1]=t1[0]-'a'+1;
		hha2[0]=0; hha2[1]=t2[0]-'a'+1;
		for(int i=1;i<llen;i++)
		{
			hha1[i+1]=(1ll*hha1[i]*B%mod+t1[i]-'a'+1)%mod;
			hha2[i+1]=(1ll*hha2[i]*B%mod+t2[i]-'a'+1)%mod;
		}
		int ans=0;
		for(int i=hea[tt];i<=n;i++)
		{
			if(a[i].t!=tt) break;
			int x=ll-a[i].l,y=x+a[i].len-1;
			if(x>=0&&y<llen)
			{
				int u=(hha1[y+1]-1ll*hha1[x]*fac[y-x+1]%mod+mod)%mod;
				int v=(hha2[y+1]-1ll*hha2[x]*fac[y-x+1]%mod+mod)%mod;
				if(a[i].ha1==u&&a[i].ha2==v) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
