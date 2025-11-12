#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5202],ans,b[5202];
void dfs(int num,int mx,int stp,int sum){
	bool flag=false;
	if(num>=3 && sum>2*mx){
		ans=(ans+1)%mod;
		flag=true;
	}
	if(stp==n+1)return;
	
	if(!flag)dfs(num,mx,stp+1,sum);
	
	dfs(num+1,max(mx,a[stp]),stp+1,sum+a[stp]);
}
//abs(a)<abs(o)
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0,1,0);
	
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

