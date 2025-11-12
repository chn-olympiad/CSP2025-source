#include<cstdio>
#include<algorithm>
using namespace std;
int a[5005],n,maxn,sum,k;
long long ans;//无论如何均存得下
bool v[5005];//用于存储用过的小木棍
const long long VAL=998244353;
bool check(){//判断能否形成多边形
	maxn=sum=0;
	for(int i=1;i<=n;i++){
		if(v[i]){
			maxn=max(maxn,a[i]);//最大值
			sum+=a[i];
		}
	}
	return (sum>(maxn*2));
}
void dfs(int start,int depth){
	if(depth==k&&check()){
		ans++;
		ans%=VAL;
		return ;
	}
	for(int i=start;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			dfs(i+1,depth+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(k=3;k<=n;k++){
		dfs(1,0);
	}
	printf("%lld",ans);
}