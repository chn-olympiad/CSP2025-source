#include<bits/stdc++.h>
using namespace std;
int n,m;
bool b[6000];
long long a[6000],ans=0;
void sn(long long gesu,long long sum,long long ma,long long dangqian){
	if(gesu==m){
		if(sum > ma*2){
			ans++;
		}
		return;
	}
	for(int i = dangqian;i<=n;i++){
		if(b[i] == 1) continue;
		ma = max(ma,a[i]);
		b[i] = 1;
		sn(gesu+1,sum+a[i],ma,i);
		b[i] = 0;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(m = 3;m<=n;m++){
		sn(0,0,0,1);
	}
	cout << ans%998244353;
	return 0;
}
