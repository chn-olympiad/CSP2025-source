#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+7;
string a[N],b[N];
int n,q,ans;

void solve(){
	string s,t;
	cin>>s>>t;
	ans=0;
	for(int i=1;i<=n;i++){
		int len=a[i].size();
		for(int j=0;j<=int(s.size())-len;j++){
			if(s.substr(j,len)==a[i]&&s.substr(0,j)+b[i]+(j+len<s.size()?s.substr(j+len,s.size()-len-j):"")==t) ans++;
		}
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(q--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
