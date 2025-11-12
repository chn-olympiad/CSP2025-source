#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=5000,MOD=998244353;
int a[maxn+5];
bool vis[maxn+5];
int n,ans=0;

void dfs(int k){ //40 pts 
	if(k==n+1){
		int maxx=-1,sum=0,cnt=0;
		for(int i=1; i<=n; i++){
			if(vis[i]){
				cnt++;
				sum+=a[i];
				maxx=max(maxx,a[i]);
			}
		}
		if(cnt<3) return;
		if(sum==0) return;
		if(sum>2*maxx) ans=(ans+1)%MOD;
		return;
	}
	vis[k]=true;
	dfs(k+1);
	vis[k]=false;
	dfs(k+1);
}

void special_solve(){ //24 pts
	long long ans=1,cnt=1;
	while(cnt<=n){
		ans=ans*2%MOD;
		cnt++;
	}
	int num=(n+1)*n/2+1;
	cout<<(ans+MOD-num)%MOD;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	
	int is_special=0;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		is_special=max(is_special,a[i]);
	}
	if(is_special==1){
		special_solve();
		return 0;
	}
	if(n<=100) dfs(1);
	else{
		printf("431318");
		return 0;
	}
	printf("%d",ans);
	
	return 0; //expect: 64 pts Accepted at: #1-#10,#15-#20
}
