#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,m,c[505],Sum=0,X[505];
bool vis[501];
char S[505];
int dfs(int t){
	int Ans=0;
	if(t>n){
		int Cnt=0;
		for(int i=1;i<=n;i++){
			if(c[X[i]]<=Cnt||S[i]=='0'){
				Cnt++;
			}
		}
		if(Cnt<=n-m) return 1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			X[t]=i;
			vis[i]=1;
			Ans=(Ans+dfs(t+1))%Mod;
			vis[i]=0;
		}
	}
	return Ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",S+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(S[i]=='1') Sum++;
	}
	if(Sum<m){
		printf("0");
		return 0;
	}
	if(n<=10){
		printf("%d",dfs(1));
		return 0;
	}
	return 0;
}
