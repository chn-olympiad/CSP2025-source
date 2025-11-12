#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
const int mod=998244353;
int n,m,c[505],p[15],opt,ans;
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++){
		if(s[i]=='1') opt++;
	}
	if(m==n){
		if(opt<n) printf("0");
		else{
			ans=1;
			for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
			printf("%d",ans);
		}
		return 0;
	}
	if(n<=10){
		for(int i=1;i<=n;i++) p[i]=i;
		do{
			int now=0;
			for(int i=1;i<=n;i++){
				if(now>=c[p[i]]) ++now;
				else if(s[i]=='0') ++now;
			}
			if(n-now>=m) ans++;
		}while(std::next_permutation(p+1,p+n+1));
		printf("%d",ans);
		return 0;
	}
	return 0;
}
