#include<iostream>
using namespace std;
int n,ans;
int a[5010],jie[5010];
bool flag[5010];
void dfs(int depth){
	if (depth>n){
		int maxu=0,sum=0;
		for (int i=1;i<=n;i++){
			if (flag[i]){
				sum+=a[i];
				maxu=max(maxu,a[i]);
			}
		}
		if (sum>maxu*2){
			ans=(ans+1)%998244353;
			return ;
		}
		else
			return ;
	}
	dfs(depth+1);
	flag[depth]=true;
	dfs(depth+1);
	flag[depth]=false;
}
int j(int x){
	if (x==0)
		return 1;
	if (jie[x])
		return jie[x];
	else{
		int ans=1;
		for (int i=2;i<=x;i++)
			ans*=i;
		jie[x]=ans;
		return jie[x];
	}
}
int c(int m,int n){
	return (j(m)/(j(m-n)*j(n)));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool p=true;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
		if (a[i]!=a[i+1])
			p=false;
	if (p){
		for (int i=3;i<n;i++)
			ans=(ans+c(n,i))%998244353;
		ans=(ans+1)%998244353;
	}
	else
		dfs(1);
	printf("%d",ans);
	return 0;
}
