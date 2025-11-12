#include <bits/stdc++.h>
using namespace std;
int n,a[5005],cnt=1;
const int mod=998244353;
bool b[5005];
void dfs(int k,int sum,int maxn){
	if(sum>(2*maxn) || k==n+1){
		if(k>=3){
			cnt++;
		}
		return ;
	}
	for(int i=k;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			maxn=max(a[k],maxn);
			/*
			if(sum>maxn && k>=3){
				cnt++;
			}
			*/
			dfs(k+1,sum+a[k],maxn);
			//dfs(k+1,sum,maxn);
			b[i]=0;
		}
	}
}
void f(){
	for(int i=n;i>=3;i--){
		cnt=(cnt*i)%mod;
	}
	cnt/=6;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n<3){
		printf("0");
		return 0;
	}
	int maxm=-100001;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxm=max(a[i],maxm);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>(2*maxm)){
			printf("1");
			return 0;
		}
		printf("0");
		return 0;
	}
	//dfs(1,0,0);
	f();
	printf("%d",cnt%mod);
	return 0;
}
