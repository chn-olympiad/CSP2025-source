//GZ-S00411 贵阳市第九中学 谈量
#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int N=10007,M=1200105;
ll n,m,k,z[11][N],s0[11],cnt,fa[N],ans,cntroad;
struct node{ll u,v,w;}a[M],b[M];

vector<node>t[32768];

bool cmp(node x,node y){return x.w<=y.w;}

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void combine(int x,int y){fa[find(x)]=find(y);}

//void tsort()
//{
//	for(int i=1;i<=cnt;i++)
//	{
//		t[a[i].w<<15].push_back(a[i]);
//	}
//	for(int i=0;i<=32767;i++)
//	{
//		for(int j=0;j<t[i].size();j++)
//		{
//			
//		}
//	}
//}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(cnt=1;cnt<=m;cnt++)
		scanf("%lld%lld%lld",&a[cnt].u,&a[cnt].v,&a[cnt].w);
	for(int i=1;i<=k;i++)
	{
		int t;
		cin>>t;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&z[i][j]);
			if(z[i][j]==0)s0[i]=j;
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cnt++,a[cnt].u=s0[i],a[cnt].v=j,a[cnt].w=z[i][j];
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
//	for(int i=1;i<=cnt;i++)
//		printf("%lld %lld %lld\n",a[i].u,a[i].v,a[i].w);

	sort(a,a+cnt+1,cmp);
	
//	cout<<endl;
//	for(int i=1;i<=cnt;i++)
//		printf("%lld %lld %lld\n",a[i].u,a[i].v,a[i].w);
//	cout<<endl;
//	cout<<'%';


	for(int i=1;i<=cnt;i++)
	{
//		cout<<find(a[i].u)<<' '<<find(a[i].v)<<endl;
		if(find(a[i].u)!=find(a[i].v))
		{
//			cout<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<<endl;
			combine(a[i].u,a[i].v);
			cntroad++,ans+=a[i].w;
			if(cntroad==n-1)break;
		}
	}
	cout<<ans;
	return 0;
}
