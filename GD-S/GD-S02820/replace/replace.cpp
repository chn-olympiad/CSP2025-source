#include<bits/stdc++.h>
using namespace std;
int main(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	unordered_map<string,string> m;
	for(int i=0;i<n;i++){
		string ss;
		cin >> ss;
		cin >> m[ss];
	}
	for(int i=0;i<q;i++){
		string sa,sb;
		int ans=0;
		cin >> sa >> sb;
		if(sa.size()!=sb.size()){
			cout << 0 << endl;
			continue;
		}
		for(auto zu:m){
			for(int j=0;j+zu.first.size()<=sb.size();j++){
				if(sa.substr(0,j)==sb.substr(0,j)&&zu.second==sb.substr(j,zu.first.size())&&zu.first==sa.substr(j,zu.first.size()) && sa.substr(j+zu.first.size(),sb.size()-(j+zu.first.size())) == sb.substr(j+zu.first.size(),sb.size()-(j+zu.first.size()))){
					ans++;
//					cout << zu.first << ' ' << zu.second << endl;
				}             
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
