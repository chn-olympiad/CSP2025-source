#include <iostream>
#include <stdio.h>
using namespace std;
int n, q, cnt;
string s1[200001], s2[200001], t1, t2;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		s1[i] = s1[i];
		s2[i] = s2[i];
	}
	while(q--){
		cnt=0;
		cin>>t1>>t2;
		t1 = t1;
		t2 = t2;
		for(int i=1;i<=n;++i){
			if(t1.size()<s1[i].size()){
				continue;
			}
			for(int j=0;j<=t1.size()-s1[i].size();++j){
				if(t1.substr(0,j)!=t2.substr(0,j))break;
				string tl1 = t1.substr(j+s2[i].size(),t1.size()-j-s2[i].size());
				string tl2 = t2.substr(t2.size()-(t1.size()-j-s2[i].size()),t1.size()-j-s2[i].size());
				if(tl1!=tl2)continue;
				if(s2[i]!=t2.substr(j,s2[i].size())||s1[i]!=t1.substr(j,s1[i].size())){
					continue;
				}
				++cnt;
			}
		}
		cout << cnt << '\n';
	}
}
