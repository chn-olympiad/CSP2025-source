#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans;
long long a[5500];
bool cmp(long long  x,long long  y){
	return x<y;
}
void dfs(int x,int num,int cnt){
	if(num>n || x>n){
		return;
	}
	for(int i=x;i<=n;i++){
		if(num>2){
			if(a[i]<cnt){
				ans++;
			}	
		}
		dfs(i+1,num+1,cnt+a[i]);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	dfs(1,1,0);
	ans%=998244353;
	printf("%lld",ans);
	return 0;
} 
