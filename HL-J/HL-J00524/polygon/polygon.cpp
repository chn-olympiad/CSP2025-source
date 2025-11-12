#include<iostream>
#define MAXN 5100
#define mod 998244353
using namespace std;
int n,A[MAXN],Is=1,ans;
int D[MAXN],Book[MAXN];
int ksm(int a,int b){
	int ans=1;
	while(b){if(b&1)ans=(ans*a)%mod;b/=2;a=(a*a)%mod;}
	return ans;
}
void dfs(int x,int m){
	if(x==m+1){
		int Sum=0,maxn=-1e9;
		for(int i=1;i<=m;i++){
			Sum+=A[D[i]];
			maxn=max(maxn,A[D[i]]);
		}
		if(Sum>2*maxn)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(Book[i]||i<=D[x-1])continue;
		D[x]=i;
		Book[i]=1;
		dfs(x+1,m);
		Book[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){cin >> A[i];if(A[i]!=1)Is=0;}
	if(Is){
		int Ans=0;
		int G=ksm(2,n);
		G=G-(n*(n-1)/2)-n-1;
		cout << G << endl;
		return 0;
	}
	else if(n==3){
		int Sum=A[1]+A[2]+A[3];
		int maxn=max(max(A[1],A[2]),A[3]);
		if(Sum>2*maxn)cout << "1" << endl;
		else cout << "0" << endl;
		return 0;
	}
	else{
		for(int i=3;i<=n;i++)dfs(1,i);
		cout << ans << endl;
	}
	return 0;
}
