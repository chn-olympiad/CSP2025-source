#include<bits/stdc++.h>
using namespace std;
int n,a[105],zsum=0,f[5005][5005];
void dfs(int x,int sum,int sum2,int maxn){
	if(x>n){
		if(sum>maxn*2) zsum++;
		return ;
	}
	dfs(x+1,sum,sum2,maxn);
	dfs(x+1,sum+a[x],sum2+1,max(a[x],maxn));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n>20){
		unsigned long long int sum=0;
		long long a=n*(n-1),b=2,c=n-2,d=3;
		for(int i=3;i<=n;i++){
			sum+=(a*c)/(b*d);
			a*=c,b*=d;
			c--;
			d++;
		}
		printf("%llu",sum);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0,0,0);
	printf("%d",zsum);
	return 0;
}
