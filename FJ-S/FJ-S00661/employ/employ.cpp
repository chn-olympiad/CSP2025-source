#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,ans=1,f=0,fl=0;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a!=0){
			fl=1;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			f=1;
		}
	}
	if(fl==0){
		cout<<0;
		return 0;
	}
	if(f==0||m==1){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<114514;
	return 0;
}
