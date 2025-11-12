#include<bits/stdc++.h>
using namespace std;
string makestring(int start , int end , string s){
	string ret = "";
	for(int i = start ; i < end ; i++) ret += s[i];
	return ret;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	int n,q;
	vector<pair<string,string>> s;
	cin >> n >> q;
	for(int i = 0 ; i < n ; i++){
		string a,b;
		cin >> a >> b;
		s.push_back({a,b});
	}
	for(int i = 0 ; i < q ; i++){
		string sa , sb;
		int ans = 0;
		cin >> sa >> sb;
		if(sa.size() == sb.size()){
			for(int a = 1 ; a < sa.size()-1 ; a++){
				for(int b = a+1 ; b < sa.size() ; b++){
					string x = makestring(0,a-1,sa);
					string y = makestring(a,b-1,sa);
					string z = makestring(b,sa.size()-1,sa);
					for(int j = 0 ; j < s.size() ; j++) if(s[j].first == y){
						y = s[j].second;
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
