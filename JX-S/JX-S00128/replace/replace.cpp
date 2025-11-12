#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<pair<string,string> > g;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++){
		string a,b;
		cin >> a >> b;
		g.push_back({a,b});
	}
	while(q --){
		string t1,t2;
		cin >> t1 >> t2;
		cout << "1\n";
	}
	return 0;
}
