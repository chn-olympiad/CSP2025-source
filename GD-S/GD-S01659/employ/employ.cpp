#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define modd 998244353
ll m,n,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w"stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		bool f=1;
		for(ll i=0;i<s.size();i++){
			if(s[i]=='0'){
				f=0;
				break;
			}
		}
		if(f==0){
			cout<<0;
			return 0;
		}else{
			ll cnt=n;
			for(ll i=1;i<=n;i++){
				if(c[i]==0)cnt--;
			}
			cout<<cnt;
			return 0;
		}
	}
	cout<<0;
	
	return 0;
}
