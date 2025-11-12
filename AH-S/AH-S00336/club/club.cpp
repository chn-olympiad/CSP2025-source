#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
pair<int,int> sum[N];
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)
			a[i]=read(),b[i]=read(),c[i]=read();
		for(int i=1;i<=n;i++)
		{
			int x=a[i],y=b[i],z=c[i];
			if(x>y) swap(x,y);
			if(y>z) swap(y,z);
			if(x>y) swap(x,y);
			sum[i]=make_pair(z-y,i);
		}
		sort(sum+1,sum+n+1,greater<pair<int,int> >());
		int x=0,y=0,z=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int id=sum[i].second;
			if(a[id]>=b[id] and a[id]>=c[id])
			{
				if(x<n/2) x++,ans+=a[id];
				else ans+=max(b[id],c[id]);
			}
			else if(b[id]>=a[id] and b[id]>=c[id])
			{
				if(y<n/2) y++,ans+=b[id];
				else ans+=max(a[id],c[id]);
			}
			else if(c[id]>=a[id] and c[id]>=b[id])
			{
				if(z<n/2) z++,ans+=c[id];
				else ans+=max(a[id],b[id]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
// Ren5Jie4Di4Ling5%
