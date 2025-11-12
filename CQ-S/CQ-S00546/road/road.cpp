#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
const int M=1e6+5;
const int T=(1<<10)+25;
const int inf=5e16L;
struct node
{
	int x,y,z;
	bool operator<(const node &b)const{return z<b.z;}
}s[M],a[15][M];
struct did
{
	int prt[N];
	int getfather(int x)
	{
		if(prt[x]==x)return x;
		return prt[x]=getfather(prt[x]);
	}
	int merge(int x,int y)
	{
		int a=getfather(x);
		int b=getfather(y);
		if(a==b)return 0;
		prt[b]=a;
		return 1;
	}
}fqr[T];
struct ooo
{
	int x,id;
};
int n,m,k,c[N],ans=inf,kong[T],rez[T][N];
void prepare()
{
	sort(s+1,s+1+m);
	for(int i=1;i<=k;i++)sort(a[i]+1,a[i]+1+n);
	for(int i=1;i<=m;i++)a[0][i]=s[i];
	for(int j=0;j<(1<<k);j++)
	{
		kong[j]=0;
		rez[j][0]=1;
		for(int i=1;i<=k;i++)
		{
			if(!((j>>i-1)&1))continue;
			rez[j][i]=1;
		}
		for(int i=1;i<=n+k;i++)fqr[j].prt[i]=i;
	}
}
ooo get(int j)
{
	ooo tmp=(ooo){inf,0};
	for(int i=0;i<=k;i++)
	{
		if(i&&(!((j>>i-1)&1)))continue;
		ooo dmp=(ooo){inf,0};
		int ss=0;
		if(!i)ss=m;
		else ss=n;
		while(rez[j][i]<=ss)
		{
			int sb=rez[j][i];
			int aa=fqr[j].getfather(fqr[j].prt[a[i][sb].x]);
			int bb=fqr[j].getfather(fqr[j].prt[a[i][sb].y]);
			if(aa==bb)
			{
				rez[j][i]++;
				continue;
			}
			dmp=(ooo){a[i][sb].z,i};
			break;
		}
		if(dmp.x<=tmp.x)tmp=dmp;
	}
	return tmp;
}
void solve()
{
	for(int j=0;j<(1<<k);j++)
	{
		for(int i=1;i<=k;i++)
		{
			if(!((j>>i-1)&1))continue;
			kong[j]+=c[i];
		}
	}
	for(int j=0;j<(1<<k);j++)
	{
		int num=0;
		for(int i=1;i<=k;i++)
		{
			if(!((j>>i-1)&1))continue;
			num++;
		}
		for(int tt=1;tt<=n+num-1;tt++)
		{
			ooo sb=get(j);
			fqr[j].merge(a[sb.id][rez[j][sb.id]].x,a[sb.id][rez[j][sb.id]].y);
			kong[j]+=sb.x;
			rez[j][sb.id]++;
		}
	}
	for(int j=0;j<(1<<k);j++)
	{
		ans=min(ans,kong[j]);
//		cout<<"cnm: "<<j<<' '<<kong[j]<<'\n';
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>s[i].x>>s[i].y>>s[i].z;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int z;
			cin>>z;
			a[i][j]=(node){n+i,j,z};
		}
	}
	prepare();
	solve();
	cout<<ans<<'\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
