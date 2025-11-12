#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[501];
int c[501];
bool ara[501];
int lued=0;

long long ans=0;
inline void dfs(int i){
	//printf("dfs:i=%d \n",i);
	if(i>n){
		if(lued>=m){
			ans++;
			ans%=998244353;
			return;
		}
	}
	for(int j=1;j<=n;j++){
		if(!ara[j]){
			ara[j]=true;
			//printf("lu:%d\n",i-1-lued);
			if(!(i-1-lued>=c[j])){
				if(s[i]=='1'){
					lued++;
				}
			}
			dfs(i+1);
			if(!(i-1-lued>=c[j])){
				if(s[i]=='1'){
					lued--;
				}
			}
			ara[j]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	bool easy=true; 
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(s[i]!='1'){
			easy=false;
		}
	}
	if(easy){
		int z=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				++z;
			}
		}
		if(z==0){
			ans=1;
			for(int i=1;i<=n-z;i++){
				ans=ans*i%998244353;
			}
			printf("%lld",ans);
			return 0;
		}
	}
	memset(ara,false,sizeof(ara));
	dfs(1);
	printf("%lld",ans);
}
