#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f; 
}
int n,cnt[3];
struct node
{
	int w,id;
	bool operator<(const node&x)const{return x.w<w;}
}a[N][3];
priority_queue<node>q;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				a[i][j].w=read();
				a[i][j].id=j;
			}
			if(a[i][0].w<a[i][1].w)swap(a[i][0],a[i][1]);
			if(a[i][0].w<a[i][2].w)swap(a[i][0],a[i][2]);
			if(a[i][1].w<a[i][2].w)swap(a[i][1],a[i][2]);
			ans+=a[i][0].w;++cnt[a[i][0].id];
			q.push({a[i][0].w-a[i][1].w,a[i][0].id});
		}
		for(int i=0;i<3;i++)
		{
			while(cnt[i]>(n>>1))
			{
				node u=q.top();q.pop();
				if(u.id!=i)continue;
				ans-=u.w;--cnt[i];
			}
		}
		cout<<ans<<endl;
		while(q.size())q.pop();
		for(int j=0;j<3;j++)cnt[j]=0;
	}
	return 0;
}
/*
*/
