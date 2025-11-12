#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int u,v,w;
};
vector<node> arr,asdf;
vector<node> a[100005];
int n,m,k,f[15][100005],fa[100015];
ll ans=0x3f3f3f3f3f3f3f3f;
bool cmp(node x,node y){
	return x.w<y.w;
}
bool flagA=true;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		node x;
		scanf("%d%d%d",&x.u,&x.v,&x.w);
		arr.push_back(x);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) scanf("%d",&f[i][j]);
		if(f[i][0]!=0) flagA=0;
	}
	if(flagA){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				arr.push_back({j,n+i,f[i][j]});
			}
		}
		sort(arr.begin(),arr.end(),cmp);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		int cnt=0;ans=0;
		for(auto dfs:arr){
			int x=dfs.u,y=dfs.v;
			if(find(x)!=find(y)){
				fa[fa[y]]=fa[x];
				ans+=dfs.w;
				cnt++;
			}
			if(cnt==n+k-1) break;
		}
		printf("%lld",ans);
	}else{
		for(int i=0;i<(1<<k);i++){
			ll mx=0;
			int cnt=n;
			asdf=arr;
			for(int j=0;j<k;j++){
				if((1<<j)&i){
					for(int wq=1;wq<=n;wq++){
						asdf.push_back({wq,n+j+1,f[j+1][wq]});
					}
					mx+=f[j+1][0];
					cnt++;
				}
			}
			sort(asdf.begin(),asdf.end(),cmp);
			for(int i=1;i<=cnt;i++) fa[i]=i;
			for(auto dfs:asdf){
				int x=dfs.u,y=dfs.v;
				if(find(x)!=find(y)){
					fa[fa[y]]=fa[x];
					mx+=dfs.w;
					cnt--;
				}
				if(cnt==1) break;
			}
			ans=min(ans,mx);
		}
		printf("%lld",ans);
	}
	return 0;
}
/*
1~4和特殊性质A可以通过最小生成树解决。
7~8可以通过2^k枚举 + 最小生成树 卡过。
预计通过14个点，获得14*4=56分，有点少（对于T2来说） 

把所有都当做特殊性质来做，最终答案再减去没有被用过的点
不可以，因为有可能为了必须联通，所以答案多连了一些点

先最小生成树一下，再对于每一个边尝试连边以减小？ 

用可行性剪枝优化，如果当前已经>ans，退出
好玄学的优化，有时候跟没有区别不大，而且最大时间复杂度在排序那里，真的跟没有似的 
思考排序优化？
基数排序是唯一有可能优化的排序，但是反而会更高？
O(9M) 好像有戏？ 
最后的数据9e8完都完了，但是除了21~25好像都能过？ 
不知道15,16的5e8过不过的了。
2e7应该是稳过？ 
18*4?
要不基数排序的基数再大一点？
基数为100000最大了，O(2M)左右，理论能过1e8，2e8有点悬，先做了来 
打完之后发现连13~14都过不了，实际可能只有32分 
得了，全改成sort吧，废了。 
*/
