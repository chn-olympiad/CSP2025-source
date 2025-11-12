#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n,a[5100];
long long ans;
void dfs(int sum,int ma,int x){
	if(sum>ma*2)
		ans++,ans%=M;
	for(int i=x;i<=n;i++)
		dfs(sum+a[i],max(ma,a[i]),i+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(0,0,1);
	printf("%lld",ans);
	return 0; 
} 
