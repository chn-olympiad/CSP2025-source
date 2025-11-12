#include<bits/stdc++.h>
using namespace std;
inline int read(){int x=0;bool b=0;signed c=getchar();while(c<48||c>57)b=c==45,c=getchar();while(c>47&&c<58)x=(x<<3)+(x<<1)+(c^48),c=getchar();return b?-x:x;}
inline void write(int x,signed c){if(!x){putchar(48),putchar(c);return;}if(x<0)x=-x,putchar(45);signed i=0,a[32];while(x)a[++i]=x%10^48,x/=10;while(i)putchar(a[i--]);putchar(c);}
struct st
{
	int a,id;
}x[5],s[5],a[100010];
bool operator<(st a,st b)
{
	return a.a<b.a;
}
int t,n,ans;
signed main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read(),ans=0,s[1]={0,1},s[2]={0,2},s[3]={0,3};
		for(int i=1;i<=n;i++)
			x[1]={read(),1},x[2]={read(),2},x[3]={read(),3},sort(x+1,x+4),a[i]={x[3].a-x[2].a,x[3].id},ans+=x[3].a,s[x[3].id].a++;
		sort(s+1,s+4),sort(a+1,a+1+n);
		if(s[3].a>n>>1)
			for(int i=1;i<=n;i++)
				if(a[i].id==s[3].id)
				{
					ans-=a[i].a,s[3].a--;
					if(s[3].a==n>>1)
						break;
				}
		write(ans,10);
	}
	return 0;
}
