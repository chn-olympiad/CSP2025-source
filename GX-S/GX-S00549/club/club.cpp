#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,n;
struct peo{
	long long num[3];
	bool go=false;
}p[N];
int check[3];
long long dfs(int x){
	if(x>n) return 0;
	long long maxn=0;
	for(int i=0;i<3;i++){
		if(check[i]<(n/2)){
			check[i]++;
			maxn=max(maxn,p[x].num[i]+dfs(x+1));
			check[i]--;
		}
	}
	return maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int ii=0;ii<t;ii++){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&p[i].num[0],&p[i].num[1],&p[i].num[2]);
			p[i].go=false;
		}
		memset(check,0,sizeof(check));
		printf("%lld\n",dfs(1));
	}
	return 0;
}
