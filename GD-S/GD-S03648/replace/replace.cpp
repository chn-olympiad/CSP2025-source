#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
ll n,q;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	vector<pair<string, string> > mp;
	
	for(int i=1; i<=n; i++){
		string t1,t2;
		cin >> t1 >> t2;
		mp.push_back({t1,t2});
	}
	while(q--){
		string t1,t2;
		cin >> t1 >> t2;
		string s1,s2;
		ll cnt=0;
		for(int i = 0;i<mp.size(); i++){
			s1 = mp[i].first, s2 = mp[i].second;
			for(int l=0;l<t1.size()-s1.size()+1;l++){
				string tmp = string(t1.begin()+l, t1.begin()+l+s1.size());
				if(tmp==s1){
					string tt1 = t1;
					tt1.erase(l, s1.size());
					tt1.insert(l, s2);
					
					if(tt1==t2)cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	
	return 0;
}
