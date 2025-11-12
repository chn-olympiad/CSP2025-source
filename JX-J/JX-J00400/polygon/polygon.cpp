#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e3+5,mod=998244353;
int n,a[N],ans;
int pw(int x,int y){
	int num=1;
	while(y){
		if(y&1) num=num*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return num%mod;
}
bool check(int x){
	int num=0,maxn=0,sum=0;
	for(int i=0;i<n;i++){
		if((x>>i)&1){
			maxn=max(maxn,a[i+1]);
			num+=a[i+1];
			sum++;
		}
	}
	if(sum<3) return 0;
	if(num>2*maxn) return 1;
	else return 0;
		
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	int e=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) e=0;
	}
	if(e){
		int ans=pw(2,n);
		cout<<((ans-n*(n-1ll)/2-n-1)%mod+mod)%mod;
		return 0;
	}
	for(int i=0;i<(1<<n);i++)
		if(check(i)) ans=(ans+1)%mod;
	cout<<ans%mod;
	return 0;
}

