#include<iostream>
#include<cstdio>
#define N 21
#define mod 998244353
using namespace std;
int f[1<<N][N],g[1<<N][N],ans;
int n,m,a[N],b[N],pp[1<<N];
int popcnt(int x){
	int cnt=0;
	while(x){
		if(x&1)cnt++;
		x>>=1;
	}
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
		b[i]=s[i-1]-'0';
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<(1<<n);i++)
		pp[i]=popcnt(i);
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<=pp[i];j++){
			for(int k=0;k<n;k++){
				if((1<<k)&i)continue;
				if(b[pp[i]+1]&&(pp[i]-j)<a[k])f[(1<<k)|i][j+1]=(f[(1<<k)|i][j+1]+f[i][j])%mod;
				else f[(1<<k)|i][j]=(f[(1<<k)|i][j]+f[i][j])%mod;
			}
		}
	}
	for(int i=m;i<=n;i++)
		ans=(ans+f[(1<<n)-1][i])%mod;
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
