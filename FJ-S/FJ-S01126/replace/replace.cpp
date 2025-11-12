#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin >>n >>q;
	vector< pair<string,string> > s;
	for(int i = 1; i <= n; i++){
		string si1,si2;
		cin >>si1 >>si2;
		s.push_back(make_pair(si1,si2));
	}
	string t1,t2;
	while(q--){
		int ans = 0;
		cin >>t1 >>t2;
		for(auto i : s){
			string s1 = i.first,s2 = i.second;
			if(t1.find(s1) == string::npos || t2.find(s2) == string::npos){
				continue;
			}
			if(t1.find(s1) == t2.find(s2)){
				int t = t1.find(s1);
				string t11 = t1;
				for(int i = t; i < t+s2.size(); i++){
					t11[i] = s2[i-t];
				}
				if(t11 == t2){
					ans++;
				}
			}
		}
		cout <<ans <<"\n";
	}
	return 0;
}
 
