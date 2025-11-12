#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=998244353;
int n,m,c[505],sum,dft[505];
long long ans;
char s[505];
bool v[505];
void dfs(int k){
	if(k>n){
		if(sum<=n-m){
			(ans+=1)%=mod;
			//for(int i=1;i<=n;i++)printf("%d ",dft[i]);
			//printf("\n%d\n",sum);
		}
		return;
	}
	if(sum>n-m)return;
	for(int i=1;i<=n;i++)if(!v[i]){
		dft[k]=i;
		v[i]=true;
		if(sum>=c[i] || s[k]=='0'){
			sum++;
			//for(int i=1;i<=k;i++)printf("%d ",dft[i]);
			//printf("\n!%d %d\n",k,sum);
			dfs(k+1);
			sum--;
		}
		else dfs(k+1);
		v[i]=false;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
