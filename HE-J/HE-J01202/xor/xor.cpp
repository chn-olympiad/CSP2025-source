#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,s[500010];
int ans;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>s[1];
	bool f=0;
	if(s[1]==k) ans++,f=1;
	for(int i=2;i<=n;i++){
		cin>>s[i];
		if(s[i]==k){
			f=1;
			ans++;
			continue;
		}else if(f){
			continue;
		}else{
			s[i]^=s[i-1];
			if(s[i]==k){
				f=1;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
