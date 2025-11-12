#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edge
{
	int u,v,w;
	int num;
} e[1000006]; //存边

bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int f[10004];
int qwp(int k)
{
	if(f[k]==k) return k;
	else return f[k]=qwp(f[k]);
}
//并查集

//最小生成树

/*struct Edge2{
	int num;//边的编号
	int y;//去到的点 
};

vector <Edge2> w[10004];

int q[10004];//存生成树的边在e[]中的编号 


queue<int>l,r;
*/
int vi[12][10005];//乡村，建议去城市化

int main()
{
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].num=i;
	}
	sort(e+1,e+1+m,cmp);
	long long ans=0;
	int cnt=0;
	for(int i=1,fx,fy;i<=m&&cnt<n-1;i++){
		fx=qwp(e[i].u);fy=qwp(e[i].v);
		if(fx==fy) continue;
		ans+=e[i].w;
		f[e[i].u]=fy;
		cnt++;
		//w[e[i].u].push_back((Edge2){e[i].num,e[i].v});
		//w[e[i].v].push_back((Edge2){e[i].num,e[i].u});//存图 
		//q[cnt]=e[i].num;
	}
	//建一棵最小生成树
	if(k==0){
		cout<<ans;
		return 0;
	}//1~4
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>vi[i][j];
		}
	}
	
	return 0;
}
//15:45 开题
//16:00 这啥
//1~4 跑一棵最小生成树
//太城市化了
//修建一个城市：花费代价，增加n条边
//10 个城市全都修建，边数来到1e6+1e5，多不了多少
//如何处理新修边的权值？
//用不上新修边当然最好，但这基本不可能
//不是这O(nm)都过不去
//那估计就是O(kn+m)了
//跑一棵最小生成树理论O(m+n)
//这个性质A有什么用呢
//哦还要开 long long
//为什么样例答案都这么小
//16:30
//由于要连接原有的城市，所以新修建的城市至少修两条路
//1. 先建最小生成树
//2. 每次断掉一条边，对两边分别对k座乡村求最短的那条边
//3. 生成树O(m)，枚举断哪条边复杂度O(n),找最短边O(knlogn)
//16:45 开写
//17:15 怎么找最短边？O(n)暴力查找啊废话 
//找完最短边后该怎么做？
//如果大于原来边则不管
//如果修改的话图也会改变哦
//那要不枚举如果修建每座乡村？ 
//17:30 去看T3暴力吧 
