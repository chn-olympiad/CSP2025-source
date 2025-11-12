#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mzk=505;
const int mod=998244353;
int n,m;
char ch[mzk];
int s[mzk];
int ord[mzk],usd[mzk];
int ans1;
int pat[mzk];
int flag1=1;
int cal(){
	int fal=0,suc=0;
	for(int i=1;i<=n;i++){
		int ppl=ord[i];
		if(!s[i]){
			fal++;continue;
		}
		if(fal>=pat[ppl]){
			fal++;continue;
		}
		suc++;
	}
	return suc;
}
void dfs(int x){
	if(x==n+1){
		if(cal()>=m) ans1++;
		ans1%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(usd[i]) continue;
		ord[x]=i;usd[i]=1;
		dfs(x+1);
		usd[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	cin>>ch;
	flag1=1;
	for(int i=1;i<=n;i++){
		s[i]=(ch[i-1]=='1')?1:0; 
		if(s[i]!=1) flag1=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&pat[i]);
	}
	if(n<=18){
		dfs(1);
		printf("%lld",ans1%mod);
		return 0;
	}
	if(flag1){
		int fine=0;
		for(int i=1;i<=n;i++){
			if(pat[i]) fine++;
		}
		if(fine<m){
			printf("0");return 0;
		}
	}
	printf("0");
	return 0;
} 
