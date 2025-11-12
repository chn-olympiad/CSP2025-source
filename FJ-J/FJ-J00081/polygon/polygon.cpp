#include<bits/stdc++.h>
using namespace std;

const int N = 5010;

int n,a[N],ans = 0,f[N];

void dfs(int k,int sum,int ma,int p){
	if(sum>ma*2 && k>=3){
		ans++;
	}
	if(k == n){
		return;
	}
	for(int i = p+1;i<=n;i++){
		if(!f[i]){
			f[i] = 1;
			dfs(k+1,sum+a[i],max(ma,a[i]),i);
			f[i] = 0;
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	dfs(0,0,0,0);
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
