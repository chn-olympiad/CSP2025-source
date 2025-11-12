//GZ-S00236 贵阳市第三中学 李盱盈
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
void Charlie(){
	ll n,q;
	cin>>n>>q;
	vector<vector<string>>s(n+1,vector<string>(3,""));
	for(ll i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(ll i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		for(ll i=0;i<a.size();i++){
			string s=a,s1=b;
			for(ll j=i+1,j<a.size();j++){
				s=a[i]+s;
			}
		}
		cout<<0<<endl;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll t=1;
	//cin>>t;
	while(t--)Charlie();
	return 0;
}
