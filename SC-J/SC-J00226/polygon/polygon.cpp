#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const int mod = 998244353;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,ans=0;
	cin>>n;
	ll x = (1<<n),y=1;
	vector<int> A(n+1);
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	sort(A.begin()+1,A.end());
	while(y<=x){
		ll sum=0,maxn=0,cnt=y,q;
		for(int i=1;(cnt!=0)&&i<=n;i++){
			if(cnt&1){
				sum += A[i];
				maxn = A[i];
				q++;
			}
			cnt>>=1;
		}
//		cout<<y<<' '<<sum<<' '<<maxn<<'\n';
		if(q>=3&&sum > maxn*2){
			ans = (ans+1)%mod;
//			cout<<sum<<'\n';
		}
		y++;
	}
	cout<<ans;
	return 0;
}