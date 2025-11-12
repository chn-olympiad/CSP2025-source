#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=510,mo=998244353;
int n,m,c[N];
char s[N];
LL f[1<<18|100][22];
LL dfs(int st,int t,int sum){
	if(st==n+1)return sum>=m;
	if(f[t][sum]!=-1)return f[t][sum];
	LL ans=0;
	for(int i=1;i<=n;i++){
		if((t>>i-1)&1)continue;
		if(st-sum-1>=c[i]||s[st]=='0'){
			ans+=dfs(st+1,t|(1<<i-1),sum);
		}else{
			ans+=dfs(st+1,t|(1<<i-1),sum+1);
		}
	}
	ans%=mo;
	return f[t][sum]=ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	memset(f,-1,sizeof(f));
	printf("%lld\n",dfs(1,0,0));
	return 0;
}
