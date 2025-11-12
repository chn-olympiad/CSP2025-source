#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans;
struct Pa{
	string s1,s2;
}s[N];
void solve(){
	string t1,t2;
	cin>>t1>>t2;
	for (int i=0;i<t1.size();i++){
		for (int j=1;j<=t1.size()-i;j++){
			string a=t1.substr(i,j);
			for (int k=1;k<=n;k++){
				if (a==s[k].s1 && t1.substr(0,i)+s[k].s2+t1.substr(i+j,t1.size()-i-j)==t2){
					ans++;
				}
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s[i].s1=s1,s[i].s2=s2;
	}
	while (q--){
		solve();
	}
	return 0;
}
