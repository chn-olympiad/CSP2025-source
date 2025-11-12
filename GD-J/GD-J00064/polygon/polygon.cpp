#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005],vis[5005];
inline void dfs(int ne,int z,int bs,int sum,int ma){
	if(bs==z){
		if(sum>ma*2){
			ans++;
			ans=ans%998244353;
		}
		return;
	}
	for(int i = ne ; i <= n ; i++){
		if(vis[i]==0){
			sum+=a[i];
			int tmp=max(ma,a[i]);
			bs++;
			vis[i]=1;
			dfs(i,z,bs,sum,tmp);
			bs--;
			vis[i]=0;
			sum-=a[i];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	
	for(int i = 3 ; i <= n ; i++){
		dfs(1,i,0,0,0);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
