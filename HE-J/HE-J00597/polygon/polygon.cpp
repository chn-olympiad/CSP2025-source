#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
const int mod=998244353;//EWEÓÐµãÄÑ  
int f[100010];
long long ans=0;
inline void dfs(int x,int sum,int num){
	for(int i=x+1;i<=n;i++){
		if(num<2){
			if(sum>a[i]){
			f[i]+=f[x],f[i]%=mod;
		}
		}
		else{
			if(sum>a[i]){
			f[i]+=f[x]+1,f[i]%=mod;
			}
			
		}
		dfs(i,sum+a[i],num+1); 
	}
}

int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	
	dfs(0,0,0);
	for(int i=3;i<=n;i++){
		ans+=f[i];ans%=mod;
	}
	printf("%d",ans);
}
