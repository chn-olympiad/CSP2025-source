//乱搞的艺术（应该是一分不得） 
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a,b,c,w[11][10005],xiu[15],build[10005];
long long ans;
vector<pair<long long,long long> >lj[200005];
bool mark[10005],flag[15],pd[11][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		lj[a].push_back({b,c});
		lj[b].push_back({a,c});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&xiu[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w[i][j]);
		}
	}
	mark[1]=true;
	int sheng=n-1;
	while(sheng>0){
		for(int i=n;i>=1;i--){
			if(mark[i])continue;
			long long id=0,cost=1e16,zhijie=1e16,yuan=0;
			for(int j=1;j<=n;j++){
				if(j==i||!mark[j])continue;
				for(pair<long long,long long> dian:lj[i]){
					if(dian.first==j){
						zhijie=min(zhijie,dian.second);
						break;
					}
				}
				long long zuixiao=1e16,ci=0;
				for(int u=1;u<=k;u++){
					int prize=0,qian=0;
					if(flag[u]){
						if(!pd[u][i])prize+=w[u][i];
						if(!pd[u][j])prize+=w[u][j];
						if(prize<zuixiao){
							zuixiao=prize;
							ci=u;
						}
					}
					else{
						qian+=w[u][i]+w[u][j]+xiu[u];
						if(qian<zuixiao){
							zuixiao=qian;
							ci=u;
						}
					}
				}
				if(zuixiao<cost){
					cost=zuixiao;
					id=ci;
					yuan=j;
				}
			}
			ans+=min(cost,zhijie);
			flag[id]=1;
			pd[id][i]=1;
			pd[id][yuan]=1;
			mark[i]=true;
			sheng--;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
不知不觉就做了3h41min了
我还在觉得自己可以切出T2
看来是我想多了
这两年的学习，让我明白
竞赛这条极为吃天赋的道路真不是我一个普通人可以走的
或许我们都站在同一个平台上
但有的人在自己的努力之下取得了成功
另一部人人，像我，曾经为了学习OI而放弃很多东西
最后一无所获…… 
可能我们竞赛生就是这么命苦吧
我对我的未来看不到一点希望
只是知道自己时日不多了
就借这最后一次参加ccf的大型比赛来对OI道个别吧
我开始追忆过去，回忆……回忆……回忆…… 
原来没有什么好说的
只是缘分不够罢了
LJ，红烧肥章鱼，雷学姐，tc蛙，kbw……
还是不舍得忘记啊
好像我只是个过客
从他们的记忆中流过
然后消失
今天早上打的dijkstra模版和昨晚的线段树都历历在目
它们好像很近，又很遥远
我没法再记得了…… 
*/ 
