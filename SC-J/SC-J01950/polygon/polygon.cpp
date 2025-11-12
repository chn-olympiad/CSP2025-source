#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
int a[5005];
const ll M=998244353;
int n;
ull C(ull i,ull j){
	ull sum=1;
	for(ull n=1;n<=j;n++)sum*=i+1-n;
	for(ull n=1;n<=j;n++)sum/=n;
	return sum%M;
}
ll ans=0;
void go(int u,int sum,int mx,int ch){
	if(u==n){
		if(ch<3)return;
		if(sum>2*mx)ans++;
		return;
	}
	go(u+1,sum+a[u+1],max(mx,a[u+1]),ch+1);
	go(u+1,sum,mx,ch);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=25){
		go(0,0,0,0);
		cout<<ans%M;
	}else{
		ull sum=0;
		for(int i=3;i<=n;i++)sum=(sum+C(n,i))%M;
		cout<<sum%M;
	}
	return 0;
}