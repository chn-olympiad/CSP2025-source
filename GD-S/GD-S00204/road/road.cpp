#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int tmp=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		tmp=(tmp<<1)+(tmp<<3)+c-'0';
		c=getchar();
	}
	return tmp*f;
}
int n,m,k;
struct MIKU
{
	int fro;
	int to;
	int len;
}a[10000001];
int fa[1000001];
int ans;
int sum;
bool cho[1000001];
int cit[1000001];
int ret;
bool cmp(struct MIKU u,struct MIKU v)
{
	return u.len<v.len;
}
int find(int u)
{
	if(fa[u]==u)
	{
		return u;
	}
	else
	{
		return fa[u]=find(fa[u]);
	}
}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	if(u!=v)
	{
		fa[u]=v;
	}
}
int Klu()
{
	int cnt=0;
	ret=0;
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		struct MIKU now=a[i];
		if(find(now.fro)==find(now.to))
		{
			continue;
		}
		ret+=now.len;
		cnt++;
		merge(now.fro,now.to);
	}
	//cout<<cnt<<endl;
	return ret;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		a[i].fro=read(),a[i].to=read(),a[i].len=read();
	}
	ans=Klu();
	for(int i=1;i<=k;i++)
	{
		sum=0;
		for(int j=1;j<i;j++)
		{
			if(cho[j])
			{
				sum+=cit[j];
			}
		}
		cit[i]=read();
		sum+=cit[i];
		for(int j=1;j<=n;j++)
		{
			int tmp=read();
			a[m+j].fro=i+n,a[m+j].to=j,a[m+j].len=tmp;
		}
		m+=n;
		sum+=Klu();
		//cout<<sum<<" "<<m<<endl;
		if(ans>=sum)
		{
			ans=sum,cho[i]=true;
		}
		else
		{
			m-=n;
			cho[i]=false;
		}
		/*for(int i=n+1;i<=k+n;i++)
		{
			cout<<fa[i]<<" ";
		}
		cout<<endl<<endl;*/
	}
	printf("%lld",ans);
	return 0;
}
