#include<bits/stdc++.h>
using namespace std;
int total,maxt,n;
long long sum,ans;
bool flag;
int a[10000];
bool vis[10000];
void dfs(int num,int x,int maxw){
	if(x==0){
		if(total>maxt*2){
			ans++;
			ans%=998244353;
		}
	}
	for(int i=1;i<=num;i++){
		if(!vis[i]){
			vis[i]=1;
			total+=a[i];
			maxt=max(maxw,a[i]);
			dfs(i,x-1,maxt);
			total-=a[i];
			maxt=maxw;
			vis[i]=0;
		}
	}
	
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);

	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	
	}


	for(int i=1;i<=n;i++){
		dfs(n,i,0);
	}
	printf("%lld",ans);
	return 0;
}
