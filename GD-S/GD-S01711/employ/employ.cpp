#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500+5,mod=998244353;
ll c[N];
ll inv[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	//我已无力回天,哪怕一年做了800+题，我终究不是天才啊,luogu id:775951 
	ll n,m;
	string s;
	cin>>n>>m>>s;
	inv[0]=1;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
		inv[i]=inv[i-1]*i%mod;
	}
	ll sum=0;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='1'){
			sum++;
		}
	}
	if(sum==s.size()){
		cout<<inv[n]/inv[n-m]/inv[m]<<'\n';
		return 0;
	}
	ll op;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='1'){
			op=i;
		}
	}
	sum=0;
	for(ll i=1;i<=n;i++){
		if(c[i]>op){
			sum++;
		}
	}
	if(m==1){
		cout<<inv[n-1]*sum%mod<<'\n';
	}else{
		cout<<"0\n";
	}
//	cout<<inv[n]/inv[n-op-1]/inv[op-1]<<" ";
	return 0; 
}
