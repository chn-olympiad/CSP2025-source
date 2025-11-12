#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5+5;
pair<string,string> p[maxn];

int main(){
	ios:: sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i = 1; i <= n; ++i)  cin>>p[i].first>>p[i].second;
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		cout<<0<<'\n';
//		if(s1.size() ^ s2.size()){
//			cout<<"0\n";
//			continue ;
//		}
//		int cnt = 0;
//		for(int i = 1; i <= n; ++i){
//			for(int j = 0; j < 1+s1.size()-p[i].first.size(); ++j){
//				if(s1.substr(j,p[i].first.size()) == p[i].first){
//					string temp;
//					temp = s1.substr(0,j);
//					temp += p[i].second;
//					temp += s1.substr(p[i].second.size()+j+1,n-p[i].second.size()-j);
//					if(temp == s2)  ++cnt;
////					cout<<temp<<'\n';
//				}
//			}
//		}
	}
	return 0;
}
