#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
const int mod=998244353;
int n,m,c[N],len;
string str;
void solve1(){
	ll ans=1;
	for(int i=2;i<=n;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
	return;
}
int main(){

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	len=str.length();
	int cnt=0;
	for(int i=0;i<len;i++){
		if(str[i]=='0'){
			cnt=1;
			break;
		}
	}
	if(cnt==0){
		solve1();
		return 0;
	}
	
	return 0;
}

