#include <bits/stdc++.h>
using namespace std;
map<pair<string, string>, int> mp;
int n, q, ans=0;
string s1, s2, t1, t2, t3, t4;
string b1, b2, e1, e2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for (int i=1; i<=n; i++){
		cin>>s1>>s2;
		mp[{s1, s2}]++;
	}
	for (int i=1; i<=q; i++){
		ans=0;
		cin>>t1>>t2;
		if (t1.length()!=t2.length()){
			cout<<0<<"\n";
			continue;
		}
		int len=t1.length();
		for (int i=0; i<len; i++){
			for (int j=1; j<=len-i; j++){
				b1=t1.substr(0, i);
				b2=t2.substr(0, i);
				t3=t1.substr(i, j);
				t4=t2.substr(i, j);
				e1=t1.substr(i+j);
				e2=t2.substr(i+j);
//				cout<<b1<<" "<<t3<<" "<<e1<<"\n";
//				cout<<b2<<" "<<t4<<" "<<e2<<"\n";
				if (b1==b2){
					if (e1==e2){
//						cout<<mp[{t3, t4}]<<"\n";
						ans+=mp[{t3, t4}];
					}
				}else{
					break;
				}
			}
		}
		cout<<ans<<"\n";
		}
}
