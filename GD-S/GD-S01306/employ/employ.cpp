#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
		cin>>s;
		for(int i=0;s[i];i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
}
