#include<bits/stdc++.h>
#define lo long long
using namespace std;
lo n,m,vis[510],ans;
string s;
struct tt{
	lo id,wait;
}a[510];
void dfs(lo num,lo defeat){
	if(num<=n){
		for(lo i=1;i<=n;i++){
			if(vis[i]==0){
				if(s[num]=='0'||a[i].wait<=defeat){
					vis[i]=1;
					dfs(num+1,defeat+1);
					vis[i]=0;
				}else{
					vis[i]=1;
					dfs(num+1,defeat);
					vis[i]=0;
				}
			}
		}
	}else{
		if(n-defeat>=m) ans=(ans+1)%998244353;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	s=' '+s;
	for(lo i=1;i<=n;i++){
		scanf("%lld",&a[i].wait);
		a[i].id=i;
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
