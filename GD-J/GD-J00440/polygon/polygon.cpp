#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,a[5010];
int b[1000010];
int p[5010];
int maxn;
int sum;
void init(){
	p[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]*2%MOD;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		for(int j=a[i]+1;j<=maxn;j++)
			sum=(sum+b[j])%MOD;
		for(int j=maxn;j>=1;j--){
			if(j+a[i]>maxn)sum=(sum+b[j]*(p[n-i]-1)%MOD)%MOD;
			else b[j+a[i]]=(b[j+a[i]]+b[j])%MOD;
		}
		for(int j=1;j<i;j++){
			if(a[i]+a[j]>maxn)sum=(sum+(p[n-i]-1))%MOD;
			else b[a[i]+a[j]]++;
		}
	}
	cout<<sum;
	return 0;
}

