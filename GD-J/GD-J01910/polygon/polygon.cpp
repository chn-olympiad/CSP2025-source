#include<cstdio>
#include<algorithm>
using namespace std;
int n,s[5001],jzs,js;
long long ans;
void dfs(int x){
	jzs+=s[x];
	js++;
	if(js>=3&&jzs>s[x]*2)ans++;
	ans%=998244353;
	if(x<n)dfs(x+1);
	jzs-=s[x];
	js--;
	if(x<n)dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		if(s[i]==1)js++;
	}
	
	
	if(js==n){
		long long a=1,b=1;
		ans=1;
		for(int i=n;i>3;i--){
			a*=i;
			a%=998244353;
			b*=(n+1-i);
			b%=998244353;
			ans+=(a/b);
			ans%=998244353;
		}
		printf("%lld",ans);
	}
	else{
		js=0;
		sort(s+1,s+n+1);
		dfs(1);
		printf("%lld",ans);
	}
	return 0;
}

