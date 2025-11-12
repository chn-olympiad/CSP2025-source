#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long N=998244353;
long long n,m;
long long s[501],c[501];
long long vis[501];
long long ans;
char a[501];
void dfs(long long u,long long day,long long die){
	
	if (c[u]<=die){
		die++;
	}
	else{
		if(s[day]==0){
			die++;
		}
	}
	for (long long i=1;i<=n;i++){
		if (!vis[i]){
			vis[i]=1;
			dfs(i,day+1,die);
			vis[i]=0;
		}
	}
	if (day==n){
		
		if (n-die>=m){
			ans++;
			ans%=N;
		}
		return ;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	
	cin>>a;
	for (long long i=0;i<strlen(a);i++){
		if (a[i]=='0'){
			s[i+1]=0;
		}
		if (a[i]=='1'){
			s[i+1]=1;
		}
	}
	for (long long i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	for (long long i=1;i<=n;i++){
		vis[i]=1;
		dfs(i,1,0);
		vis[i]=0;
	}
	printf("%lld",ans%N);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
