#include <cstdio>
using namespace std;
#define ll long long

int n, ans, tmp;
ll a[500005], k, pre[500005];

void dfs(int f){
	if(f >=  n){
		if(tmp > ans) ans=tmp;
		return ;
	}
	
	for(int i=f;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(pre[j]^pre[i-1] == k){
				tmp++;
				dfs(j+1);
				tmp--;
			}
		}
	}
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d%lld", &n, &k);
	for(int i=1;i<=n;i++){
		scanf("%lld", &a[i]);
		pre[i]=a[i]^a[i-1];
	}
	
	if(n <= 1000){
		dfs(1);
		printf("%d", ans);
		return 0;
	}
	else{
		printf("%d", n);
	}
	
	return 0;
}
