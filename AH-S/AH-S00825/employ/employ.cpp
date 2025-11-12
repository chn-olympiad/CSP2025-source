#include<bits/stdc++.h>
using namespace std;
const int maxn=520,mod=998244353;
string a;
int n,m,b[maxn],sum=1,cnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(m==1){
		for(int i=n;i>=1;i--){
			sum=((sum%mod)*(i%mod))%mod;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=0){
			cnt++;
		}
	}
	for(int i=cnt;i>=1;i--){
		sum=((sum%mod)*(i%mod))%mod;
	}
	cout<<sum;
	return 0;
}
