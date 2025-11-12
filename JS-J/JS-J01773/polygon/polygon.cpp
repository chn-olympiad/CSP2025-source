#include <bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int f[5001];
int jie(int x){
	int sum=1;
	for(int i=2;i<=x;i++){
		sum*=i;
		//sum%=998244353;
	}
	return sum;
}
int c(int x,int y){
	return (jie(y)/(jie(x)*jie(y-x)))%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<3){
		cout <<0 << endl;
		return 0;
	}
	if(n>20){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=c(i,n);
			ans%=998244353;
		}
		cout << ans << endl;
	}
	return 0;
}
