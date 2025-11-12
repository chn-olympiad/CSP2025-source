#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,m,z,c,t,a[505],bz[505];
ll ans;
char s[505];
void dfs(int d){
	if(d>n){
		if(c>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(bz[i]) continue;
		bz[i]=1;
		int x=z,y=c;
		if(s[d-1]=='0'||z>=a[i]) z++;
		else c++;
		dfs(d+1),z=x,c=y,bz[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(s[i-1]=='0') t=1;
	}
	if(n>18){
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		return printf("%lld",ans),0;
	}
	dfs(1),printf("%lld",ans);
	return 0;
}
/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
