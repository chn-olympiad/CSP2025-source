#include <bits/stdc++.h>
using namespace std;
struct aa{int a,b,c;}a[100005];
bool cmp(aa l,aa r)
{
    if(l.a>l.b&&l.a>l.c&&l.a!=r.a) return l.a>r.a;
    else if(l.b>l.a&&l.b>l.c&&l.b!=r.b) return l.b>r.b;
    else if(l.c>l.a&&l.c>l.b&&l.c!=r.c) return l.c>r.c;
    else if(l.a!=r.a) return l.a>r.a;
    else if(l.b!=r.b) return l.b>r.b;
    else if(l.c!=r.c) return l.c>r.c;
    else return l.a>r.a;
}
int px1(int i,long long f,long long &x,long long &y,long long &z)
{
    int maxn=max(a[i].a,max(a[i].b,a[i].c)),ans;
    ans=0;
    if(maxn==a[i].a&&x<f) ans+=a[i].a,x++;
    else if(maxn==a[i].b&&y<f) ans+=a[i].b,y++;
    else if(maxn==a[i].c&&z<f) ans+=maxn,z++;
    else if(maxn==a[i].a&&x>=f)
    {
        if(a[i].b>a[i].c&&y<f) ans+=a[i].b,y++;
        else ans+=a[i].c,z++;
    }
    else if(maxn==a[i].b&&y>=f)
    {
        if(a[i].a>a[i].c&&x<f) ans+=a[i].a,x++;
        else ans+=a[i].c,z++;
    }
    else if(maxn==a[i].c&&z>=f)
    {
        if(a[i].a>a[i].b&&x<f) ans+=a[i].a,x++;
        else ans+=a[i].b,y++;
    }
    return ans;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	long long t,n,f,x,y,z,ans;
	scanf("%lld",&t);
	while(t>0)
	{
	    printf("");
		scanf("%lld",&n);
		f=n/2;
		ans=x=y=z=0;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
        {
			ans+=px1(i,f,x,y,z);
		}
		printf("%lld\n",ans);
		t--;
	}
	return 0;
}
