#include<bits/stdc++.h>
using namespace std;
const int N=2e4+1;
inline int read()
{
	register int x=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9')
		x=x*10+c-48,c=getchar();
	return x;
}
int T,n,a[100010],b[100010],c[100010],cnt[4],ans;
bool cmp(int a,int b)
{return a>b;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)
			a[i]=read(),b[i]=read(),c[i]=read();
		if(n==2)
		{
			if(a[1]<a[2]) swap(a[1],a[2]);
			if(b[1]<b[2]) swap(b[1],b[2]);
			if(c[1]<c[2]) swap(c[1],c[2]);
			cout<<max(a[1]+b[1],max(a[1]+c[1],b[1]+c[1]))<<endl;
			continue;
		}
		ans=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)
			ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
}
