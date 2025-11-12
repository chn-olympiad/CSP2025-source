#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[10005][3];
int flag[10005];
long long club[3];
long long T,n,ans;
bool cmp(long long a,long long b){
	return a>b;
}
void dfs(long long depth){
	if (depth>n){
		long long t=0;
		for (long long i=1;i<=n;i++)
			t+=a[i][flag[i]];
		ans=max(ans,t);
		return ;
	}
	if (club[0]<(n/2)){
		flag[depth]=0;
		club[0]++;
		dfs(depth+1);
		flag[depth]=-1;
		club[0]--;
	}
	if (club[1]<(n/2)){
		flag[depth]=1;
		club[1]++;
		dfs(depth+1);
		flag[depth]=0;
		club[1]--;
	}
	if (club[2]<(n/2)){
		flag[depth]=2;
		club[2]++;
		dfs(depth+1);
		flag[depth]=0;
		club[2]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while (T--){
		bool p=true;
		ans=0;
		scanf("%lld",&n);
		for (long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			if (a[i][1]!=0 || a[i][2]!=0)
				p=false;
			flag[i]=-1;
		}
		if (p){
			long long c[10005];
			memset(c,sizeof(c),0);
			for (long long i=1;i<=n;i++)
				c[i]=a[i][0];
			sort(c+1,c+1+n,cmp);
			for (long long i=1;i<=(n/2);i++)
				ans+=c[i];
			printf("%lld",ans);
			continue;
		}
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
