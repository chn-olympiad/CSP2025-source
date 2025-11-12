#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int mod=998244353;
vector<int>a(N,0);
long long fact(int x,int n){
	long long ans=1;
	n=n-x+1;
	while(n){
		ans*=n;
		n-=2;
		ans%=mod;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n==3){
		cout<<1;
		return 0;
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=fact(i,n);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}