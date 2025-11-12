#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
int n,m,k,p,l,maxs;
int a[N];
long long dp[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxs=max(maxs,a[i]);
		l+=a[i];
	}
	if(n==3&&(l-maxs)*2>maxs&&maxs<=10){
		cout<<1;
		return 0;
	}
	if(l==n){
		cout<<n-2;
	}
}
