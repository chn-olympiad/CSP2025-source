#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,P=998244353;
int n,m;
char s[N];
ll ans=0,c[N];
bool b[N];
inline void dfs(int k,int refuse){ 
	if(k>n){
		if(n-refuse>=m)
			ans++;
		return;
	}
	for(int i=1;i<=n;i++)if(!b[i]){
		b[i]=true;
		if(refuse>=c[i]||s[k]=='0'){
			dfs(k+1,refuse+1);
		}else{
			dfs(k+1,refuse);
		}
		b[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(b,0,sizeof b);
	scanf("%d%d",&n,&m);
	ans=0;
	scanf("%s",s+1); 
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
