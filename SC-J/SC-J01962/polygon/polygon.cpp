#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e3+10;
const int MOD=998244353;

int n;
int a[N],q[N];

int A(int m,int n){
	int sum=1;
	for(int i=1;i<=m;i++){
		sum*=(n-i+1);
	}
	return sum;
}

int C(int m,int n){
	return A(m,n)/A(m,m);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxa=0;
	bool flag1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag1=0;
		q[i]=q[i-1]+a[i];
		maxa=max(maxa,a[i]);
	} 
	if(n<=2){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(q[n]>maxa*2) cout<<1;
		else cout<<0;
		return 0;
	}
	else if(flag1){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans=(ans+C(i,n))%MOD;
		}
		cout<<ans%MOD;
		return 0;
	}
	return 0;
}


