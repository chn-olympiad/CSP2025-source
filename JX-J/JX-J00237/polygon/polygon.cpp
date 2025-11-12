#include <bits/stdc++.h>
using namespace std;
#define mod 998244353

int a[5010];
int n,sum=0,cnt=0;
void dfs(int x,int y){
	if (x>=3 && sum>a[y]*2) cnt=(cnt+1)%mod;
	for (int i=y+1;i<=n;i++){
		sum+=a[i];
		dfs(x+1,i);
		sum-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dfs(0,0);
	printf("%d",cnt);
}
