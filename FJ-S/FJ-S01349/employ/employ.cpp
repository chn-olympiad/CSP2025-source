#include <bits/stdc++.h>
using namespace std;

bool f=true;
long long n,m,c[510],cc,ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(long long i=0,len=s.size();i<len;i++){
		if(s[i]=='0'){
			f=false;
		}
	}
	for(long long i=1;i<=n;i++){
		cin >> c[i];
		if(c==0){
			cc++;
		}
	}
	if(n==m){
		if(cc==0 && f){
			ans=1;
			for(long long i=2;i<=n;i++){
				ans=ans*i%998244353;
			}
			cout << ans;
		}else{
			cout << 0;
		}
		return 0;
	}
	cout << 0;
	return 0;
}
