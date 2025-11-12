#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long s;

void dfs(int t,int st,int m,int max1){
	if(t>n) return ;
	if(t>=3){
		if(m>(max1<<1))
			s=(s+1)%998244353;
	}
	for(int i=st+1;i<=n;i++)
		dfs(t+1,i,m+a[i],max(max1,a[i]));
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(0,0,0,0);
	printf("%lld",s);
	return 0;
}
