#include<bits/stdc++.h>
#define P pair<int,int> 
#define fi first
#define se second
using namespace std;
priority_queue<P,vector<P >,greater<P > > q;
int n,m,ct,cw[100],ne,h[10100],nn;
long long ans=1e16,sum,cnt;
bool js[10100],v[100100];
struct line{
	int to,nx,w;
}e[4000010];
void add(int x,int y,int z)
{
	e[++ne].to=y;
	e[ne].w=z;
	e[ne].nx=h[x];
	h[x]=ne; 
}
void dfs(int k)
{
	if(k>ct){
		memset(v,0,sizeof(v));
		cnt=0;
		while(!q.empty()) q.pop();
		v[1]=1;
		for(int i=h[1];i;i=e[i].nx)
		{
			int to=e[i].to;
			if(!v[to]&&js[to]){
				q.push(P(e[i].w,to));
			}
		}
		
		for(int g=1;g<=nn;g++)
		{
			int k=q.top().se;
			while(v[k]||!js[k]){
				q.pop();
				if(!q.empty()) k=q.top().se;
				else{
					ans=min(ans,sum+cnt);
//					
//					cout<<" x ";
//					
					return;
				}
			}
			v[k]=1;
			cnt+=q.top().fi;
			for(int i=h[k];i;i=e[i].nx)
			{
				int to=e[i].to;
				if(!v[to]&&js[to]){
					q.push(P(e[i].w,to));
				}
			}
		}
		ans=min(ans,sum+cnt);
//		
//		cout<<" / ";
//		
		return;
	} 
	 
	js[n+k]=1; ++nn; sum+=cw[k];
	dfs(k+1);
	js[n+k]=0; --nn; sum-=cw[k];
	dfs(k+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>ct;
	int x,y,z;
	for(int i=1;i<=m;++i)
	{ 
		cin>>x>>y>>z;
		add(x,y,z);add(y,x,z);
	}	
	for(int i=1;i<=n;i++) js[i]=1;
	for(int i=1;i<=ct;++i)
	{
		cin>>cw[i];
		for(int j=1;j<=n;++j)
		{
			cin>>z;
			add(n+i,j,z);add(j,n+i,z);
		}
	}
//	
//	cout<<0<<"\n";
//	 
	nn=n;
	dfs(1);//来吧伟大的暴力！ 
	cout<<ans;
	return 0;
 } 
//25	19	D:\GD-S*****\road\road.cpp	[Error] 'class std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > >' has no member named 'clear'
//25	19	D:\GD-S*****\road\road.cpp	[Error] 'class std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > >' has no member named 'clean'
//欸那啥来着还是我记错了？ 

//欸不是你怎么不运行了呀？？？#74  i=50547
//wakao 最多50547对吧50548不给输入 
//？？？这对吗？？？ <(#▼- ▼)>
//也不是文件头 
//？？？ 居然是js数组的问题 不可以和输入循环一起处理 
//暴力果然超时 _(.o - 0.)_ 
//？？？怎么是输入的问题 
//补药哇我快读快写不熟 ( T ^ T )  
//？？？是电脑被我搞坏了吗为什么输入最后一个要卡5秒还有答案也是错的啊是对的我看错了
//所以你们这些做奇葩程序大赏的可不可以帮本蒟蒻小妹妹看看这码啊啊啊啊不想改了 （叫我姐姐也行我最后一次csp了但是我会蹲洛谷找你们的 
//froepen(".in","w",stdin);
//不行我要当个淑女 

//k=10的时候输入最后一个直接卡死了好耶！\(Ovo)/   -->快疯了从来没有遇到过
//取消关掉的流可以输入完了 
//??我算法好像有点问题？ 
//不想调了 电脑的问题和我脑子出问题只会发生一个 
//si xin @sisi_ xiexie 咕哩~
//wo zhe zhou yao shui bu zhao le  
 
