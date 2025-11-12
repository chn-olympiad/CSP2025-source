#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long a[50001],ans,n;
map<string,bool> m;
void dfs(long long x,long long sum,long long ma,int cnt,string s){
	if(cnt>=3&sum>ma*2&&!m[s]){
		m[s]=1;
		ans++;
		ans%=mod;
	}
	if(x>n)
		return;
	dfs(x+1,sum,ma,cnt,s);
	ma=max(ma,a[x]);
	dfs(x+1,sum+a[x],ma,cnt+1,s+(char)(x+'0')); 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	string s="";
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1,0,0,0,s);
	printf("%lld",ans);
	return 0;
} 
