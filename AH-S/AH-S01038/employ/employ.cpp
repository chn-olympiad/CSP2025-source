#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
long long ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		if(c==0)cnt++;
	}
	for(int i=n-cnt;i>=n-cnt-m+1;i--){
		ans*=i;
		ans%=998244353;
	}
	if(m>(n-cnt))cout<<0;
	cout<<ans;
	return 0;
}
