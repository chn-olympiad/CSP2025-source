#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=2e6+10;
pair<int,pair<int,int> > l[M];
int c[30][N],fa[N],top[N];
typedef long long ll;
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

int mv(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = mv(fa[x]);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	bool A=true;
	for(int i=1;i<=m;i++)
	{
		l[i].second.first=read();
		l[i].second.second=read();
		l[i].first=read();	
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		c[i][0]=read();
		if(c[i][0]) A=false;
		bool B=false;
		for(int j=1;j<=n;j++)
		{
			c[i][j]=read();
			if(!c[i][j])
			{
				if(!B) top[i]=j;
				B=true;
			}
		}
		if(!B) A=false;
	}
	ll ans=0;
	if(A)
	{
		if(k)
		{
			for(int i=1;i<=k;i++)
				for(int j=1;j<=n;j++)
					l[++m]=make_pair(c[i][j],make_pair(top[i],j));
		}
		sort(l+1,l+m+1);
		int p=n,i=0;
		while(p>1 and i<=m)
		{
			i++;
			int x=l[i].second.first,y=l[i].second.second;
			int cnt=l[i].first;
			if(mv(x)==mv(y)) continue;
			ans+=cnt;
			fa[fa[y]]=fa[x];
			p--;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
// Ren5Jie4Di4Ling5%
