#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#define int long long
using namespace std;
int T,n;
struct nx
{
	int x,y,z;
}a[100010];
int v[100010];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
    	cin>>n;
    	for(int i=1;i<=n;i++)
             scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
        memset(v,0,sizeof(v));
        int a1=0,a2=0,a3=0,ans=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            int x=a[i].x,y=a[i].y,z=a[i].z;
        	int maxx=max(x,max(y,z));
        	if(maxx==x) {a1++,ans+=x;continue;}
        	if(maxx==y) {a2++,ans+=y;continue;}
        	if(maxx==z) {a3++,ans+=z;continue;}
        }
        if(a1>n/2)
        {
        	for(int i=1;i<=n;i++)
        	{
        		int x=a[i].x,y=a[i].y,z=a[i].z;
        	    int maxx=max(x,max(y,z));
        	    if(maxx==x) v[++cnt]=x-max(y,z);
        	}
        	int l=a1-n/2;
        	sort(v+1,v+cnt+1);
        	for(int i=1;i<=a1-n/2;i++)
        	{
        		ans-=v[i];
        	}
        	cout<<ans<<endl;
        	continue;
        }
        if(a2>n/2)
        {
        	for(int i=1;i<=n;i++)
        	{
        		int x=a[i].x,y=a[i].y,z=a[i].z;
        	    int maxx=max(x,max(y,z));
        	    if(maxx==y&&maxx!=x) v[++cnt]=y-max(x,z);
        	}
        	int l=a2-n/2;
        	sort(v+1,v+cnt+1);
        	for(int i=1;i<=a2-n/2;i++)
        	{
        		ans-=v[i];
        	}
        	cout<<ans<<endl;
        	continue;
        }
        if(a3>n/2)
        {
        	for(int i=1;i<=n;i++)
        	{
        		int x=a[i].x,y=a[i].y,z=a[i].z;
        	    int maxx=max(x,max(y,z));
        	    if(maxx==z&&maxx!=x&&maxx!=y) v[++cnt]=z-max(x,y);
        	}
        	int l=a3-n/2;
        	sort(v+1,v+cnt+1);
        	for(int i=1;i<=a3-n/2;i++)
        	{
        		ans-=v[i];
        	}
        	cout<<ans<<endl;
        	continue;
        }
        cout<<ans<<endl;
    }
	return 0;
}












