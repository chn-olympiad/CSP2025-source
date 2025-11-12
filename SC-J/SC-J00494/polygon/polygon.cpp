#include<bits/stdc++.h>
using namespace std;

long long n,a[5005],ans=0,s[5005];
long long rec[5005],vis[5005];
bool check(long long c){
	long long mx=rec[c-1]*2,co=0;
	for(long long i=0;i<c;i++){
		co+=rec[i];
	//	cout<<rec[i]<<' ';
	}
	
	if(co<=mx)return 0;
	return 1;
}
void dfs(long long num,long long t){
	if(num>n){
		if(t<3)return;
		if(check(t)){
			ans++;
			
		}
		return;
	}
	if(vis[num]==0){
		vis[num]=1;
		rec[t]=a[num];
		dfs(num+1,t+1);
		vis[num]=0;
		
	}
	dfs(num+1,t);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	dfs(1,0);
	printf("%lld",ans%998244353);
	
	return 0;
}