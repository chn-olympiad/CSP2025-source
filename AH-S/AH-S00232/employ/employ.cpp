#include<bits/stdc++.h>
using namespace std;
string s;
int c[505];
const long long M=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	bool f=0;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]=='0') f=1; 
	}
	if(!f){
		long long ans=1;
		for(int i=n;i>=n-m+1;i--){
			ans*=i;
			ans%=M;
		}
		for(int i=n-m;i>=1;i--){
			ans/=i;
			ans%=M;
		}
		cout<<ans;
	}
	return 0;
}
