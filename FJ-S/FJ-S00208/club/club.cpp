#include<algorithm>
#include<iostream>
#include<cstdio>
#define ll long long
inline void write(ll x)
{
	if(x<0)putchar(45),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
inline ll read()
{
	ll x=0;bool c=0;char a=getchar();
	for(;a<'0'||a>'9';a=getchar())c|=a==45;
	for(;a>='0'&&a<='9';a=getchar())x=(x<<3)+(x<<1)+(a^48);
	return c?-x:x;
}
#define R read()
using namespace std;

ll T;
ll n,ans1=0,ans2=0,ans3=0,t[3];
struct S
{
	ll x,y,id;
	bool operator<(const S B)const{return y-x>B.y-B.x;}
}a[100002],b[100002],c[100002];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	T=R;
	while(T--)
	{
		n=R;
		ans1=ans2=ans3=0;
		for(ll i=1;i<=n;++i)
		{
			ll x=R,y=R,z=R;
			a[i].x=x,a[i].y=max(y,z);
			if(y==z)a[i].id=1;
			else if(y>z)a[i].id=2;else a[i].id=3;
			b[i].x=y,b[i].y=max(x,z);
			if(x==z)b[i].id=1;
			else if(x>z)b[i].id=2;else b[i].id=3;
		}
		sort(a+1,a+1+n);
		t[1]=t[2]=t[3]=0;
		for(ll i=1;i<=n;++i)
		{
			for(;i<=n/2||a[i].y>a[i].x;++i)
			{
				if(a[i].id>1)
				{
					if(t[a[i].id]<n/2)++t[a[i].id],ans1+=a[i].y;
					else ans1+=a[i].x;
				}
				else ans1+=a[i].y;
			}
			ans1+=a[i].x;
		}
		sort(b+1,b+1+n);
		t[1]=t[2]=t[3]=0;
		for(ll i=1;i<=n;++i)
		{
			for(;i<=n/2||b[i].y>b[i].x;++i)
			{
				if(b[i].id>1)
				{
					if(t[b[i].id]<n/2)++t[b[i].id],ans2+=b[i].y;
					else ans2+=b[i].x;
				}
				else ans2+=b[i].y;
			}
			ans2+=b[i].x;
		}
		sort(c+1,c+1+n);
		t[1]=t[2]=t[3]=0;
		for(ll i=1;i<=n;++i)
		{
			for(;i<=n/2||c[i].y>c[i].x;++i)
			{
				if(c[i].id>1)
				{
					if(t[c[i].id]<n/2)++t[c[i].id],ans3+=c[i].y;
					else ans3+=c[i].x;
				}
				else ans3+=c[i].y;
			}
			ans3+=c[i].x;
		}
		write(max(ans1,max(ans2,ans3))),putchar(10);
	}
	return 0;
}
