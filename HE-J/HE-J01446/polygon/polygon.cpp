#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int N=5010;
int n;
int a[N];
int C(int x,int y){
	int sum1=1,sum2=1,sum3=1;
	for(int i=1;i<=x;i++){
		sum1=sum1*i%MOD;
	}
	for(int i=1;i<=y;i++){
		sum2=sum2*i%MOD;
	}
	for(int i=1;i<=(x-y);i++){
		sum3=sum3*i%MOD;
	}
	return sum1/(sum2*sum3%MOD)%MOD;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=3;i<=n;i++){
		sum+=C(n,i);
		sum%=MOD;
	}
	cout<<sum;
	return 0;
}
