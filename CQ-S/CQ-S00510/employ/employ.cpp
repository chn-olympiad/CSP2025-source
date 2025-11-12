#include<iostream>
using namespace std;
const long long mod=998244353;
long long n,m;
string s;
long long c[506];
long long ans=0;
long long dfs(long long a,long long b,long long d){
	if(a+d==n){
		if(a>=m){
			ans++;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if((b&(1<<i-1))==0){
			if(d>=c[i]||s[a+d+1]=='0'){
				dfs(a,b^(1<<i-1),d+1);
			}else{
				dfs(a+1,b^(1<<i-1),d);
			}
		}
	}
}
long long f1[270006][26];
long long lo[270006];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	long long ta=true;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			ta=false;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	if(n<=18){
		long long tip=(1<<n);
		f1[0][0]=1;
		for(int i=0;i<tip-1;i++){
			for(int j=1;j<=n;j++){
				long long g=(1<<j-1);
				lo[i^g]=lo[i]+1;
				if((i&g)==0){
					for(int k=0;k<=lo[i];k++){
						if(lo[i]-k>=c[j]||s[lo[i]+1]=='0'){
							f1[i^g][k]+=f1[i][k];
							if(f1[i^g][k]>=mod)f1[i^g][k]-=mod;
						}else{
							f1[i^g][k+1]+=f1[i][k];
							if(f1[i^g][k]>=mod)f1[i^g][k]-=mod;
						}
					}
				}
			}
		}
		for(int i=m;i<=n;i++){
			ans+=f1[tip-1][i];
			if(ans>=mod)ans-=mod;
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
/*
只能打个20暴力了

150 min : 172 
*/

