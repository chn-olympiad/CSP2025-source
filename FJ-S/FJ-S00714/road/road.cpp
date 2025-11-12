#include<bits/stdc++.h>
#define int long long
//#define int unsigned int
using namespace std;
int n,m,k;
struct edge
{
	int u,v,w,no;
};
vector<edge>e;
//int mend[10010][10010];
int bcj[10010];
int md[11][10010];
//bool is[11][10010];
//bool al[11];
int c[11];
int getf(int x)
{
	if(bcj[x]==x) return x;
	return bcj[x]=getf(bcj[x]);
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
//int getprice(int p,int x,int y)
//{
//	if(!al[p]) return c[p]+md[p][x]+md[p][y];
//	else return (is[p][x]^1)*md[p][x]+(is[p][y]^1)*md[p][y];
//}
int read()
{
	int f=1,dat=0;
	char ch=getchar();
	while(ch<'0'&&ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		dat=dat*10+(ch-'0'),ch=getchar();
	return f*dat;
}
void print(long long x)
{
	if(x>=10) print(x/10);
	putchar((x%10)+'0');
}
main()
{
	ifstream cin("road.in",ios::in);
	ofstream cout("road.out",ios::out);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	int start=clock();
	cin>>n>>m>>k;
//	cout<<n<<m<<k<<endl;
//	return 0;
	bool spe=true;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<i;j++) mend[i][j]=INT_MAX;
	long long sum=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edge ex;
		ex.u=x,ex.v=y,ex.w=z,ex.no=0;
		e.push_back(ex);
		sum+=z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		spe&=(c[i]==0);
		for(int j=1;j<=n;j++)
			cin>>md[i][j];
	}
//	cout<<clock()-start<<endl;
//	start=clock();
//	if(k==0){
//	sort(e.begin(),e.end(),cmp);
//	for(int i=1;i<=n;i++) bcj[i]=i;
//	unsigned long long ans=0;
//	for(auto it:e)
//	{
////		cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
//		if(getf(it.u)!=getf(it.v))
//			ans+=it.w,a[it.u].push_back(it.v),a[it.v].push_back(it.u),bcj[getf(it.u)]=getf(it.v);
//	}
//	if(k==0)
//	{
//		cout<<ans;
//		return 0;
//	}
////		cout<<clock()-start<<endl;
////		start=clock();
//	}
	long long fin=LONG_LONG_MAX;
	bool bailei[11];
	for(int i=1;i<=k;i++)
	{	
		if(c[i]>sum)
		{
			bailei[i]=true;
			continue;
		}
		else bailei[i]=false;
		for(int j=1;j<=n;j++)
		{
			edge ex;
			ex.u=j,ex.v=n+i,ex.w=md[i][j],ex.no=i;
			e.push_back(ex);
		}
	}
	sort(e.begin(),e.end(),cmp);
//	cout<<clock()-start<<endl;
//	start=clock();
	for(int mask=0;mask<(1<<k);mask++)
	{
//		cout<<mask<<endl;
		bool is[11]={true};
		long long ans=0;
		int cnt=0;
		bool youbl=false;
		for(int i=1;i<=k;i++)
			if(mask&(1<<(i-1)))
			{
				ans+=c[i];
				is[i]=true;
				if(bailei[i])
				{
					youbl=true;
					break;
				}
				cnt++;
			}
			else is[i]=false;
		if(youbl) continue;
//		cout<<mask<<endl;
//		for(auto it:e)
//			cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
		for(int i=1;i<=n+k;i++) bcj[i]=i;
		int countcount=0;
		for(auto it:e)
			if(is[it.no])
			{
				int fu=getf(it.u);
				int fv=getf(it.v);
				if(fu!=fv)
					ans+=it.w,bcj[min(fu,fv)]=max(fu,fv),countcount++;
				if(countcount==n+cnt-1) break;
			}
//		cout<<ans<<endl;
		fin=min(fin,ans);
//		cout<<clock()-start<<endl;
//		start=clock();
//		cout<<getf(1)<<endl;
	}
	cout<<fin;
}





//#include<bits/stdc++.h>
////#define int unsigned int
//using namespace std;
//int n,m,k;
//struct edge
//{
//	int u,v,w,no;
//};
//vector<edge>e;
////int mend[10010][10010];
//int bcj[10010];
//int md[11][10010];
////bool is[11][10010];
////bool al[11];
//int c[11];
//int getf(int x)
//{
//	if(bcj[x]==x) return x;
//	return bcj[x]=getf(bcj[x]);
//}
//bool cmp(edge x,edge y)
//{
//	return x.w<y.w;
//}
////int getprice(int p,int x,int y)
////{
////	if(!al[p]) return c[p]+md[p][x]+md[p][y];
////	else return (is[p][x]^1)*md[p][x]+(is[p][y]^1)*md[p][y];
////}
//vector<int>a[10010];
//int mend[10010][10010];
//int read()
//{
//	int f=1,dat=0;
//	char ch=getchar();
//	while(ch<'0'&&ch>'9')
//	{
//		if(ch=='-') f=-1;
//		ch=getchar();
//	}
//	while(ch>='0'&&ch<='9')
//		dat=dat*10+(ch-'0'),ch=getchar();
//	return f*dat;
//}
//void print(long long x)
//{
//	if(x>=10) print(x/10);
//	putchar((x%10)+'0');
//}
//main()
//{
//	freopen("road2.in","r",stdin);
////	freopen("road.out","w",stdout);
//	int start=clock();
//	n=read(),m=read(),k=read();
////	cout<<n<<m<<k<<endl;
////	return 0;
//	bool spe=true;
////	for(int i=1;i<=n;i++)
////		for(int j=1;j<i;j++) mend[i][j]=INT_MAX;
//	for(int i=1;i<=m;i++)
//	{
//		int x=read(),y=read(),z=read();
//		mend[max(x,y)][min(x,y)]=z;
//		edge ex;
//		ex.u=x,ex.v=y,ex.w=z,ex.no=0;
//		e.push_back(ex);
//	}
//	for(int i=1;i<=k;i++)
//	{
//		c[i]=read();
//		spe&=(c[i]==0);
//		for(int j=1;j<=n;j++)
//			md[i][j]=read();
//	}
//	print(clock()-start);
//	putchar('\n');
//	start=clock();
//	if(k==0){
//		sort(e.begin(),e.end(),cmp);
//		for(int i=1;i<=n;i++) bcj[i]=i;
//		unsigned long long ans=0;
//		for(auto it:e)
//		{
////		cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
//			if(getf(it.u)!=getf(it.v))
//				ans+=it.w,a[it.u].push_back(it.v),a[it.v].push_back(it.u),bcj[getf(it.u)]=getf(it.v);
//		}
//		if(k==0)
//		{
//			cout<<ans;
//			return 0;
//		}
//		print(clock()-start);
//		putchar('\n');
//		start=clock();}
//	long long fin=2147483647;
//	for(int i=1;i<=k;i++)
//		for(int j=1;j<=n;j++)
//		{
//			edge ex;
//			ex.u=j,ex.v=n+i,ex.w=md[i][j],ex.no=i;
//			e.push_back(ex);
//		}
//	sort(e.begin(),e.end(),cmp);
//	print(clock()-start);
//	putchar('\n');
//	start=clock();
//	for(int mask=0;mask<(1<<k);mask++)
//	{
////		cout<<mask<<endl;
//		bool is[11]={true};
//		long long ans=0;
//		int cnt=0;
//		for(int i=1;i<=k;i++)
//			if(mask&(1<<(i-1)))
//			{
//				ans+=c[i];
//				is[i]=true;
//				cnt++;
//			}
//		else is[i]=false;
////		cout<<mask<<endl;
////		for(auto it:e)
////			cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
//		for(int i=1;i<=n+k;i++) bcj[i]=i;
//		for(auto it:e)
//			if(is[it.no])
//			{
//				int fu=getf(it.u);
//				int fv=getf(it.v);
//				if(fu!=fv)
//					ans+=it.w,bcj[min(fu,fv)]=max(fu,fv);
//			}
////		cout<<ans<<endl;
//		fin=min(fin,ans);
//		print(clock()-start);
//		putchar('\n');
//		start=clock();
////		cout<<getf(1)<<endl;
//	}
//	print(fin);
//}
