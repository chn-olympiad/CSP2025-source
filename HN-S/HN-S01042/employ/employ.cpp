#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,c,x;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=1;i<=n;i++){
		if(s[i]=='0'){
			cout<<0;
			return 0;
		}
	}
	x=n;
	for(long long i=1;i<=n;i++){
		cin>>c;
		if(c==0){
			x--;
		}
	}
	for(long long i=x;i>0;i--){
		ans*=i;
		ans%=998244353;
		cout<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}

