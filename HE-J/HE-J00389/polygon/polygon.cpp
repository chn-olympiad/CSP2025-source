#include <bits/stdc++.h>
using namespace std;
int n,a[5001];
const int Mod = 998244353;
long long sum;
inline void dfs(int i,long long num,int k){
	if (i==n)
	    return;
	for (int j = i+1;j <= n;j++){
		if (k>=3&&num>a[j]){
			sum++;
			sum%=Mod;
		}
		dfs (j,num+a[j],k+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)
	    scanf ("%d",&a[i]);
	sort (a+1,a+n+1);
	dfs(0,0,0);
	printf ("%lld",sum);
}
