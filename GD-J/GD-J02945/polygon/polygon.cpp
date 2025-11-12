#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,MOD=998244353;
long long n,a[N],b[N][N],maxn,sum;
long long f(){
	b[0][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++){
			b[i][j]=(b[i-1][j]+b[i-1][j-1])%MOD;
		}
	}
	long long res=0;
	for(int i=4;i<=n+1;i++){
		res=(res+b[n][i])%MOD;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		cout << f();
	}
}
