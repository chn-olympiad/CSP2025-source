#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],ans = 0;
int yq(int l,int r){
	int ans = a[l];
	for(int i = l + 1;i <= r;i++) ans ^= a[i];
	return ans;
}
void dfs(int u,int st){
	ans = max(ans,u);
	for(int i = st;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(yq(i,j) == k || (i == j && a[j] == k)){
				dfs(u + 1,j + 1);
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	if(n <= 15){
		dfs(0,1);
		printf("%d",ans);
	}else{
		for(int i = 1;i <= n;i++) if(a[i] == k) ans++;
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
