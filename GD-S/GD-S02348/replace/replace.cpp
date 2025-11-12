#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
vector<int> c[200005];
string s1,s2,t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s1 >> s2;
		int tmp=s1.find('b')-s2.find('b');
		c[tmp].push_back(s1.size());
	}
	for(int i = 1;i <= q;i++){
		cin >> t1 >> t2;
		int cha=t1.find('b')-t2.find('b'),ans=0;
		for(auto x : c[cha]){
			if(x<=t1.size()){
				ans++;
			}
		} 
		cout << ans << endl;
	}
	return 0;
}
