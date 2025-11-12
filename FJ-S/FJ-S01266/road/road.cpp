#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int x,y,z;
};
int n,m,k,fa[114514],c[114],faa[114514],qwq,fath[114514],gx,K,aaa[114],temp,minn[114514],bf[114514],minc,qwqq[114514],testtt,mm[114514],qwq114=1e18,sum;
pair<int,int> a[114514];
vector<pair<int,int>> g[114514],yh[114514];
vector<node> b,ans;
map<int,int> awa[11451];
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int qu(int x)
{
	if(fa[x]==x)
	return x;
	//fa[x]=qu(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	//将y合并到x
	fa[y]=x; 
	qu(y); 
}

void kkk()
{
	for(int i=0;i<b.size();i++)
	{
		if(qu(b[i].x)!=qu(b[i].y))
		{
			merge(qu(b[i].x),qu(b[i].y));
			ans.push_back({b[i].x,b[i].y,b[i].z});
			faa[b[i].y]=b[i].z,bf[b[i].y]=b[i].z;
			g[b[i].y].push_back({b[i].x,b[i].z});
		}
	}	
	testtt=qu(1);
	for(int i=1;i<=n;i++)
	{
	if(faa[i]==-1)
	qwq=i;
	else
	minc+=faa[i];
//	if(qu(i)!=testtt)
//	cout<<i; 
//cout<<minc;

	}
	qwq114=min(qwq114,minc);
}
void dfs(int step)
{
	int temp=1;
	while(fath[temp])
	awa[fath[temp]][step]=1,temp++;
	fath[temp]=step;
	for(int i=0;i<g[step].size();i++)
	dfs(g[step][i].first);
}
void dfs2(int step,int sum)
{
	if(step>k)
	{
		for(int i=1;i<=k;i++)
		if(aaa[step])
		{
			for(int j=0;j<yh[i].size();j++)
			{
				mm[yh[i][j].second]=max(mm[yh[i][j].second],yh[i][j].first);
			}
		}
		for(int i=1;i<=n;i++)
		temp+=mm[i]; 
		temp-=sum;
		minc=min(minc,qwq114-temp);
		for(int i=1;i<=n;i++)
		mm[i]=0;
		return;
	}
	aaa[step]=1;
	dfs2(step+1,sum+c[step]);
		aaa[step]=0;
	dfs2(step+1,sum);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=n;i++)
fa[i]=i,faa[i]=-1;
for(int i=1,x,y,z;i<=m;i++)
{
	cin>>x>>y>>z;
	b.push_back({x,y,z});
//	if(b[i].z==86248539)
//	cout<<b[i].x<<' '<<b[i].y<<endl;
}
sort(b.begin(),b.end(),cmp);
kkk();
dfs(qwq);
K=k;
//for(int i=1;i<=n;i++)
//if(!mm[i])
//cout<<i<<' ';
for(int t=1;t<=k;t++)
{
	cin>>c[t];
	n++;
	for(int j=1;j<=n-t;j++)
	cin>>a[j].first,b.push_back({j,n,a[j].first});
	sort(b.begin(),b.end(),cmp);
	minc=0;
	kkk();
//	//首先我们先算这个点的贡献
//	c[t]+=a[1].first;
//	sort(a+1,a+n+1);
////	yh[t].push_back({faa[a[1].second]-a[1].first,a[1].second});
//	 int flag=1;
//	 for(int i=1;i<=n;i++)
//	 {
//	 	if(a[i].first<faa[a[i].second])
//	 	yh[t].push_back({faa[a[i].second]-a[i].first,a[i].second});
//	 	if((!awa[a[i].second][a[1].second]&&!awa[a[1].second][a[i].second])||a[1].second==qwq)
//	 	flag=0;
//	 }
//	 if(flag)
//	 for(int i=1;i<=n;i++)
//	 {
//	 	if(!awa[a[i].second][a[1].second]&&!awa[a[1].second][a[i].second])
//	 	{
//	 	c[t]+=a[i].first-faa[a[i].second];
//	 	break;
//	 	}
//	 }
////	 for(int i=0;i<yh[t].size();i++)
////	 cout<<yh[t][i].first<<' '<<yh[t][i].second<<endl;
////	 cout<<c[t]<<endl;
}
//cout<<qwq;
		cout<<qwq114;
return 0;
}
//一眼最小生成树
//形式化的，你可以以c_j的代价启用某个点，之后跑最小生成树
//一个点是否能有贡献，关键在于其是否能优化某条路径
//既在原图跑完最小生成树后，再依次考虑每个点是否要启用
//相当于说你可以花c_j的价格，优化某几条边
//考虑完这个后就好做了 
//手搓的最小生成树还真能跑？
//存疑
//一个点是否会被加入，关键在于其贡献是否大于成本
//这个问题还算好解决
//我们只要取k个乡村里，每个乡村相比于原来和其它乡村的优势边就行
//哦实则不然
//好像要换一个最小生成树
//怎么感觉和gesp的题好像
//诶不对啊
//如果一条边原本不在最小生成树上
//那他进来后应该在吗
//显然他进来只能替换一条边
//这个边为原来某点进入最小生成树的边
//那还真只要取优势边
//等等我怎么又不对了
//我好好想想
//哦如果所有自己的优势边弄完后 
//现在的问题就转化为 
