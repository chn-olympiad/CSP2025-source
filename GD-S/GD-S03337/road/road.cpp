#include<bits/stdc++.h>
#define ll long long
using namespace std;
//注意返回值 Ren5Jie4Di4Ling5%
const int N=1e4+5,M=1e6+5,K=15;
int fa[N];
int findfa(int x){
	if(x==fa[x])return x;
	return fa[x]=findfa(fa[x]); 
}
struct edge{
	int u,v;
	ll w;
}e[M],newe[M];
int ree[N*K];//remain edges
ll add[K][N];
bool v[N];
/*
注意 long long 
注意 long long 
注意 long long 
注意 long long 
注意 long long 
*/
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
//	system("FC ROAD4.ANS ROAD4.OUT");
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m,[](edge x,edge y){
		return x.w<y.w;
	});
	int ecnt=0;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;ll w=e[i].w;
		u=findfa(u),v=findfa(v);
		if(u==v)continue;
		fa[u]=v;
		ree[++ecnt]=i;
		ans+=w;
	}
	for(int i=1;i<n;i++){
		e[i]=e[ree[i]];
		//cerr<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
	}
	//now a MSTree of O(N)
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)cin>>add[i][j];
	}
	for(int S=0;S<(1<<k);S++){
		int newecnt=ecnt;
		ll s=0;
		for(int i=1;i<=ecnt;i++)newe[i]=e[i];
		for(int i=1;i<=k;i++){
			if(S&(1<<(i-1))){
				s+=add[i][0];
				for(int j=1;j<=n;j++){
					++newecnt;
					newe[newecnt].u=n+i,newe[newecnt].v=j,newe[newecnt].w=add[i][j];
				}
			}
		}
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		sort(newe+1,newe+1+newecnt,[](edge x,edge y){
			return x.w<y.w;
		});
		ecnt=0;
		for(int j=1;j<=newecnt;j++){
			int u=newe[j].u,v=newe[j].v;ll w=newe[j].w;
			u=findfa(u),v=findfa(v);
			if(u==v)continue;
			fa[u]=v;
			ree[++ecnt]=j;
			s+=w;
		}
		if(s<ans)ans=s;
		ecnt=n-1;
	}
	/*
	int ad=0;
	for(int adn=1;adn<=k;adn++){
		ll mn=ans;
		int pos;
		for(int i=1;i<=k;i++)if(!v[i]){
			ll s=ad+add[i][0];
			for(int j=1;j<=ecnt;j++)newe[j]=e[j];
			int newecnt=ecnt;
			for(int _=1;_<=n;_++){
				++newecnt;
				newe[newecnt].u=n+i,newe[newecnt].v=_,newe[newecnt].w=add[i][_];
			}
			for(int j=1;j<=n+k;j++){
				fa[j]=j;
			}
			sort(newe+1,newe+1+newecnt,[](edge x,edge y){
				return x.w<y.w;
			});
			ecnt=0;
			for(int j=1;j<=newecnt;j++){
				int u=newe[j].u,v=newe[j].v;ll w=newe[j].w;
				u=findfa(u),v=findfa(v);
				if(u==v)continue;
				fa[u]=v;
				ree[++ecnt]=j;
				s+=w;
			}
			if(s<mn){
				mn=s;pos=i;
			}
			ecnt--;
		}
		if(mn<ans){
			//cerr<<adn<<" "<<ad<<" "<<pos<<endl;
			for(int j=1;j<=ecnt;j++)newe[j]=e[j];
			int newecnt=ecnt;
			for(int _=1;_<=n;_++){
				++newecnt;
				newe[newecnt].u=n+pos,newe[newecnt].v=_,newe[newecnt].w=add[pos][_];
			}
			for(int j=1;j<=ecnt;j++){
				e[j]=newe[ree[j]];
			}
			ad+=add[pos][0];
			v[pos]=1;
			ans=mn;
		}else break;
	}
	*/
	cout<<ans;
	return 0;
}
/*
注意：乡镇是另外的，原有城市没变
k<=10 !!!
15:05
思路：k 超小，可以 2^k 枚举。
刚开始 Om 先跑出 MST 把边的数量变成 On 的。
然后枚举每个乡镇是否用上。
这就相当于重新加边后再跑 MST 了。
边是 O(KN log(KN)) 的， 
(+O(orig MST))
15:29 我忽略排序复杂度了，直接这样做可能过不了。
但是如果原来加上这一个乡镇的最优解大于原来的MST，说明这个乡镇不加。
每个尝试加一下，先看第一个，再看……
这样就是O(K)的枚举了！OK
那就是 K* KN log(KN)，绝对能过 
正确性？样例 WA 了再说。
15:53 ROAD4 是唯一强的大样例。 
前面有问题，因为可以去掉一个前面的加上后面的。 
16:27 放弃思考，打前面那个可能 T 的带 2^k 的玩意了。 
我不到啊，我甚至想过二分答案。
18:21 那期望得分大概是 80 吧…… 
*/
