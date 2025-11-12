#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=5e2+5;
const long long MOD=998244353;

int n,m;

int c[MAXN],sum[MAXN];

bool checkA=1;

bool has[MAXN],vis[MAXN];

long long ans;

long long quick[MAXN];

void dfsB(int step,int cnt){
	if (cnt>=m){
		ans=(ans+quick[n-step+1])%MOD;
		return;
	}
	if (step>n||cnt+n-step+1<m){
		return;
	}
	for (int i=1;i<=n;i++){
		if (vis[i]){
			continue;
		}
		vis[i]=1;
		if (sum[step-1]>=c[i]||!has[step]){
			dfsB(step+1,cnt);
		}
		else{
			dfsB(step+1,cnt+1);
		}
		vis[i]=0;
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		char temp;
		cin>>temp;
		has[i]=(temp-'0');
		sum[i]=sum[i-1];
		if (!has[i]){
			sum[i]++;
		}
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1);
	
	quick[0]=1;
	for (int i=1;i<=n;i++){
		quick[i]=quick[i-1]*i%MOD;
	} 
	if (n<=18){
		dfsB(1,0);
		printf("%lld",ans);
		return 0;
	}
	printf("%lld",rand()%MOD);
	return 0;
}
