#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long cnt;
void dfs(int s,long long sum,int maxn){
	if(sum>maxn*2){
		cnt++;
		cnt%=998244353;
	}
	if(s==n)return;
	for(int i=s+1;i<=n;i++){
		dfs(i,sum+a[i],max(maxn,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0,INT_MIN);
	printf("%lld",cnt);
	return 0;
}
