#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n,a[5050];
long long cnt;
bool v[5050];
void dfs(int x,int ans,int y,int maxn,int jj){
	if(x==y+1){
		if(ans>maxn*2){
			cnt++;
			cnt%=M;
		}
	}
	else{
		for(int i=jj+1;i<=n;i++){
			dfs(x+1,ans+a[i],y,max(maxn,a[i]),i);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=3;i<=n;i++){
		dfs(1,0,i,0,0);
	}
	printf("%lld",cnt);
	return 0;
}
