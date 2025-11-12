#include <bits/stdc++.h>
#define md 998244353
#define ll long long
using namespace std;
const int MN=100501;
int n,a[MN],d[MN];
ll cnt,ans;
void dfs(int s,int o,int m){
	if(o==m+1){
		int maxx=0;ans=0;
		for(int i=1;i<=m;i++){
			maxx=max(maxx,d[i]);
			ans+=d[i];
		}if(ans>2*maxx)cnt=(cnt+1)%md;
	}for(int i=s;i<=n;i++){
		d[o]=a[i];
		dfs(i+1,o+1,m);
	}
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}for(int m=3;m<=n;m++){
		dfs(1,1,m);
	}printf("%lld",cnt);
	return 0;
}
/*
8:20  进考场，发现没题目 
8:46  重启，开始比赛
8:56  切T1
9:11  切T2
10:21 用贪心写完T3发现假了，开始思考
11:43 才用DP写完T3，感觉好废物
11:48 写完，RP++ 
*/ 
