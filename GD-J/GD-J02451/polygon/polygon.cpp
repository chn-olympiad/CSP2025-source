#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ans,ma,sum;
void dfs(long long l,long long d){
	if(l>=3&&sum>ma*2){
		ans++;
	}
	if(l>n)return;
	for(int i=d+1;i<=n;i++){
		if(a[i]>ma){
			int ls=ma;
			ma=a[i];
			sum+=a[i];
			dfs(l+1,i);
			ma=ls;
			sum-=a[i]; 
		}else{
			sum+=a[i];
			dfs(l+1,i);
			sum-=a[i];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(1,0);
	printf("%lld",ans%998244353);
	return 0;
} 
