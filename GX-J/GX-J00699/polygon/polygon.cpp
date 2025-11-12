#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5010],pre[5010];
long long d[5010],prd[5010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	d[3]=1,prd[3]=1;
	for(int i=2;i<=5000;i++){
		d[2+i]=(d[1+i]*2+i)%mod;
		prd[i+2]=(prd[i+1]+d[i+2])%mod;
	}
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	if(n==3){
		if(pre[n]>2*a[1])cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<prd[n];
	return 0;
}
