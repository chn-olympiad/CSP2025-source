#include <bits/stdc++.h>
using namespace std;
int n,a[5001];
long long ans;
void pick(int i,int len,long long sum,int maxn){
	if(i==n+1){
		if(len<3){
			return;
		}
		if(sum>2*maxn){
			ans++;
		}
		return;
	}
	pick(i+1,len,sum,maxn);
	len++;
	sum+=a[i];
	maxn=max(maxn,a[i]);
	pick(i+1,len,sum,maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int MAXN=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		MAXN=max(a[i],MAXN);
	}
	if(MAXN==1){
		ans=1;
		long long zi=n*(n-1)*(n-2),mu=6;
		ans+=(zi/mu);
		for(int i=4;i<n;i++){
			zi*=(n-i+1);
			mu*=i;
			ans+=(zi/mu);
		}
		cout << ans%998244353;
		return 0;
	}
	pick(1,0,0,0);
	cout << ans%998244353;
} 
