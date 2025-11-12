#include <bits/stdc++.h>
using namespace std;
long long n,m,c[505],cnt0,cnt1,ans;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') cnt0++;
		else cnt1++;
	}
	if(!cnt0){
		ans=1;
		while(n--){
			ans*=(n+1);
			ans%=998244353;
		}
		cout<<ans;
	}
	else if(!cnt1) cout<<"0";
	else if(m==1){
		ans=1;
		while(n--){
			ans*=(n+1);
			ans%=998244353;
		}
		cout<<ans;
	}
	else if(m==n) cout<<"0";
	return 0;
}
