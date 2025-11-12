#include<bits/stdc++.h>
using namespace std;

const int N=5e3+7,MAXN=1<<20,mo=998244353;
unsigned long long ans=0;
int n,val[N],sum=0,maxn=0;
unsigned long long sun[N];
bool vis[MAXN];

void dfs(int x,int c,int sum,int maxm,int vic){
	if(x>=3&&maxm*2<sum&&(!vis[vic])){
		ans++;
		vis[vic]=true;
		ans%=mo;
	}
	if(c>n)return;
	
	for(int i=c;i<=n;i++){
		vic=vic|(1<<(i-1));
		dfs(x+1,i+1,sum+val[i],max(maxm,val[i]),vic);
		vic=vic^(1<<(i-1));
		dfs(x,i+1,sum,maxm,vic);
	}
	
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
		sum+=val[i];
		maxn=max(maxn,val[i]);
	}
	if(n==3){
		if(maxn*2>=sum){
			printf("0");
		}else{
			printf("1");
		}
		
	}else if(n<=20){
		dfs(0,1,0,0,0);
		printf("%lld",ans%mo);
	}else if(maxn==1){
		sun[1]=1;
		sun[0]=0;
		for(int i=2;i<=n;i++){
			sun[i]=sun[i-1]*i;
		}
		for(int i=3;i<n;i++){
			ans=ans+sun[n]/(sun[i]*sun[n-i]);
			ans%=mo;
		}
		printf("%lld",ans);
	}else{
		
	}
	return 0;
}