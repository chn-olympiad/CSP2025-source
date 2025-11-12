#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,a,ans,cnt;
string s;
bool f;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			f=1;
		} 
	}
	for(int i=1;i<=n;i++){
		cin>>a;
		if(!a){
			cnt++;
		} 
	}
	if(m+cnt>n){
		cout<<0;
		return 0;
	}
	if(!f){
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}
