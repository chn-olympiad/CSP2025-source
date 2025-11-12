#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int n,q,ans=0;
vector<pair<string,string>> s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		cin >> s1 >> s2;
		s.push_back(make_pair(s1,s2));
	}
	while(q--){
		cin >> s1 >> s2;
		if(s1.size() != s2.size() || s1.size() == 1){
			printf("0\n");
			continue;
		}
		for(int i=0;i<s.size();i++){
			int length = s[i].first.size();
			for(int j=0;j<=s1.size()-length;j++){
				if((s1.substr(0,j) == s2.substr(0,j) && s[i].first == s2.substr(j,length) && s1.substr(j+length,s1.size()) == s2.substr(j+length,s2.size())) || (s1.substr(0,j) == s2.substr(0,j) && s[i].second == s2.substr(j,length) && s1.substr(j+length,s1.size()) == s2.substr(j+length,s2.size()))){
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
		ans = 0;
	}
	return 0;
}
