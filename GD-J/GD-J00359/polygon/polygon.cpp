#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[3005];
bool res[3005];
void dfs(int cnt, int deep){
	if(deep==n+1){
		if(cnt<3){
			return ;
		}else{ 
			int i, tmp, sum=0;
			for(i=n; i>=1; i--){
				if(res[i]==1){
					tmp=a[i];
					sum+=a[i];
					break;
				}
			}
			i--;
			for(;i>=1; i--){
				if(res[i]==1){
					sum+=a[i];
				}
			}
			if(sum>tmp*2){
				ans++;
			}
			return ;
		}
		return;
	}
	res[deep]=0;
	dfs(cnt, deep+1);
	res[deep]=1;
	dfs(cnt+1, deep+1);
} 
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	} 
	dfs(0, 1);
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
