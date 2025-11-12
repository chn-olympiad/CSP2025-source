#include<bits/stdc++.h>
using namespace std;
map<string,bool> fl;
map<string,int> dp;
int n , q;
string tos[2][200005] , en;
bool f[200005];
int dfs(string s){
	if(s==en)return 1;
	if(fl[s])return dp[s];
	fl[s] = 1;
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		string tmp =  "";f[i] = 1;
		for(int j=0;j<s.size()-tos[0][i].size()+1;j++){
			if(s.substr(j,tos[0][i].size())==tos[0][i]){
				string cnt = tmp + tos[1][i];
				if(j+tos[0][i].size()<s.size())cnt += s.substr(j+tos[0][i].size(),s.size()-j-tos[0][i].size());
				dp[s] += dfs(cnt);
			}
			tmp += s[j];
		}
		f[i] = 0;
	}
	return dp[s];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++)cin >> tos[0][i] >> tos[1][i];
	while(q--){
		string tm;cin >> tm >> en;
		if(tm.size()!=en.size()){
			cout << "0\n";
			continue;
		}
		fl.clear() , dp.clear();
		cout << dfs(tm) << "\n";
	}
	return 0;
}
