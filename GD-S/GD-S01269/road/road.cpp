/*
15:31  完蛋了，现在才开题没救了。 
15:33  感觉像稍微变形的最小生成树 
15:47  开打！ 
15:59  20pts 部分分到手
16:15  打完开调 
16:37  过样例！！！ 
16:40  大样例死活跑不出来就这样吧QwQ 感觉要爆0了。。 
*/
#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k;
struct node
{
	int u,v,w;
}arr[M];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int f[N];
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int val[K];
int a[K][N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>arr[i].u>>arr[i].v>>arr[i].w;
	}
	sort(arr+1,arr+m+1,cmp);
	for(int i=1;i<=k;i++)
	{
		cin>>val[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n+k;i++)
	{
		f[i]=i;
	}
	int cnt=0,ans=0;
	for(int i=1;i<=m&&cnt<n-1;i++)
	{
		int u=find(arr[i].u),v=find(arr[i].v),w=arr[i].w;
		if(u!=v)
		{
			f[u]=f[v];
			ans+=arr[i].w;
			cnt++;
			arr[cnt]=arr[i];//直接替换，正确？？ 
		}
	}
	if(k<=0)
	{//部分分20pts 
		cout<<ans;
		return 0;
	}
//	int minn=ans;
//	for(int i=1;i<=cnt;i++)cout<<arr[i].u<<" "<<arr[i].v<<" "<<arr[i].w<<"\n";
	for(int i=1;i<=k;i++)
	{//枚举每个乡村的加入
		int minn=val[i];
		for(int j=1;j<=n;j++)
		{//并查集初始化 
			f[j]=j;
		}
		for(int j=1;j<=n;j++)
		{//加入边 
			arr[++cnt]={n+i,j,a[i][j]};
		}
		sort(arr+1,arr+m+n+1,cmp);
//		for(int i=1;i<=cnt;i++)cout<<arr[i].u<<" "<<arr[i].v<<" "<<arr[i].w<<"\n";
		//最小生成树
		int have=0;
//		cout<<"\n";
		for(int j=1;j<=cnt&&have<n+i-1;j++)
		{
			int u=find(arr[j].u),v=find(arr[j].v),w=arr[j].w;
//			cout<<u<<" "<<v<<" "<<w<<"\n";
			if(u!=v)
			{
				f[u]=f[v];
				minn+=arr[j].w;
				have++;
			}
		}
//		cout<<minn<<"<-minn\n";
		if(ans>minn)
		{
			ans=minn;
		}
	}
	cout<<ans<<"\n";
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
