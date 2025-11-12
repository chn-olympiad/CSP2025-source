#include<cstdio>
#include<algorithm>
using namespace std;
struct ss{int a,b,c;}
bia[1000005],MST[10005],allin[110005];
int n,m,k,fa[10015];
long long mstmst,ans;
int c[15],cst[15][10005];
bool cc(ss a,ss b){return a.c<b.c;}
void init(){for(int i=1;i<=n+k;i++) fa[i]=i;}
int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	f=(f<<1)+(f<<3)+ch-48,ch=getchar();
	return f;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) 
	bia[i].a=read(),
	bia[i].b=read(),
	bia[i].c=read();
	sort(bia+1,bia+m+1,cc);init();
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		cst[i][j]=read();
	}
	for(int i=1,cnt=0;i<=m;i++)
	{
		if(cnt==n-1) break;
		if(fnd(bia[i].a)==fnd(bia[i].b)) continue;
		cnt++,MST[cnt]=bia[i],mstmst+=bia[i].c,
		fa[fnd(bia[i].a)]=fnd(bia[i].b);
	}ans=mstmst;
	for(int kk=1;kk<(1<<k);kk++)
	{
		long long sum=0,ttot=n-1,tott=n;
		init();for(int i=1;i<n;i++) allin[i]=MST[i];
		for(int j=0;j<k;j++) if((kk>>j)&1)
		{
			sum+=c[j+1],tott++;
			for(int i=1;i<=n;i++)
			ttot++,allin[ttot].a=i,
			allin[ttot].b=tott,
			allin[ttot].c=cst[j+1][i];
		}
		sort(allin+1,allin+ttot+1,cc);
		for(int i=1,cnt=0;i<ttot;i++)
		{
			if(cnt==tott-1) break;
			if(fnd(allin[i].a)==fnd(allin[i].b))
			continue;cnt++,sum+=allin[i].c,
			fa[fnd(allin[i].a)]=fnd(allin[i].b);
		}if(sum<ans) ans=sum;//printf("%lld\n",sum);
	}printf("%lld",ans);
}
