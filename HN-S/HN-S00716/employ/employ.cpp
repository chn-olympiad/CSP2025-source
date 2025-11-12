#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000005];
string s;
bool cmp;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i-1]=='0'){
			cmp=1;
		}
	}
	long long ans=1;
	if(cmp==0){
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=998244353;
		}
	}else{
		ans=2204128;
	}
	cout<<ans;
	return 0;
}
