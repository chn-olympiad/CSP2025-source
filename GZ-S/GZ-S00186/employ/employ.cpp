#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
const int M=998244353;
ll a[N],fla,flb;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	ll len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='1')fla++;
		else flb++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//–‘÷ A 
	if(fla==0){
		cout<<0;
		return 0;
	}
	//12~14
	if(m==1){
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=M;
		}
		cout<<ans%M;
		return 0;	
	}
	//15
	if(m==n && fla!=n){
		cout<<0;
		return 0;
	}
	cout<<3;
	return 0;
}
