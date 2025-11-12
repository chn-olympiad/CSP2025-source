#include<bits/stdc++.h>
using namespace std;
const int N=5020;
const int mod=998244353;
int a[N];
bool se[N];
int n;
int ret=0;
long long sum[N];
void dfs(int s){
	if(s>n){
		int mx=0;
		int s=0;
		for(int i=1;i<=n;i++)if(se[i]){
			mx=max(mx,a[i]);
			s+=a[i];
		}
		if(mx*2<s){
//			for(int i=1;i<=n;i++){
//				printf("%d ",se[i]);
//			}puts("END");
			ret++;
		}
		return;
	}
	dfs(s+1);
	se[s]=1;
	dfs(s+1);
	se[s]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool flag=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) flag=0;
	}
	sum[0]=1;
	for(int i=1;i<=n;i++){
		sum[i]=(sum[i-1]*i)%mod;
	}
	if(flag){
		long long ret=0;
		for(int i=3;i<=n;i++){
			ret=(ret+sum[n]/sum[n-i]/(sum[i]))%mod;
		}
		printf("%d\n",ret);
		return 0;
	}
	dfs(1);
	printf("%d\n",ret);
	return 0;
}
/*
The Earth is an amazing planet!
Some places are very hot,like the areas near the equater,some are freezing code,
like the north and south poles.There are fields and mountains,rivers and seas,
forests and deserts.The highest mountain is over ten thousand metres above sea
levels,and the deep
*/
