#include<iostream>
#include<algorithm>
const int MOD=998244353;
long long sz[1000005];
int n;
long long jsq;
bool cmp(int a,int b){
	return a<b;
}
void dfs(int x,long long sum,int s){
	if(x==n+1){
		if(sum>2*sz[s]) jsq=(jsq%MOD+1)%MOD;
		return ;
	}
	dfs(x+1,sum+sz[x],x);
	dfs(x+1,sum,s);
	return ;
}
int main(){
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::cin>>n;
	for(int i=1;i<=n;i++)
		std::cin>>sz[i];
	std::sort(sz,sz+n+1,cmp);
	sz[0]=100000000;
	dfs(1,0,0);
	std::cout<<jsq;
	return 0;
}
//记得关注释！