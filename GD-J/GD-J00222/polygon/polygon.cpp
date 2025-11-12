#include<cstdio>
#include<algorithm>
#define mod 998244353
using namespace std;

int n,ans,tmp,a[5005];
void dfs(int prev,int sum,int max_num){
	if(sum>2*max_num)
		ans%=mod,ans++;
	for(int i=prev+1;i<=n;i++) dfs(i,sum+a[i],max(max_num,a[i]));
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tmp=max(tmp,a[i]);
	}
	if(tmp<=1){
		ans=1;
		for(int i=1;i<=n;i++) ans%=mod,ans*=2;
		ans-=(((n*(n-1)/2)%mod+n)%mod+1);
		printf("%d",ans);
		return 0;
	}
	dfs(0,0,0);
	printf("%d",ans);
	return 0;
}
