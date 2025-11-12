#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 50;
int n,q;
string s[N][2];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		bool f = 1,ff = 1;
		int ans = 0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i = 0;i < t1.size();i++){
			if(t1[i] != t2[i]) ans++;
		}
		for(int i = 1;i < t1.size();i++){
			if(t1[i] == t1[i - 1]) f = 0;
			else{
				f = 1;
				break;
			}
		}
		for(int i = 1;i < t2.size();i++){
			if(t2[i] == t2[i - 1]) ff = 0;
			else{
				ff = 1;
				break;
			}
		}
		if((f && ff) && t1.size() != 1 && t2.size() != 1)
			cout<<ans<<endl;
		else if(!f || !ff || t1.size() == 1 || t2.size() == 1) cout<<0<<endl;
	}
	
	return 0;
}
