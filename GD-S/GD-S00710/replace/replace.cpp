#include<bits/stdc++.h>
using namespace std;

map<string,pair<bool,string> > cg;
map<string,bool> vis;
string t2;

string change(string a,string b,int st){
	string ans = a;
	for(int i = st,j = 0;i < st + b.size() - 1;i ++,j ++){
		ans[i] = b[j];
	}
	return ans;
}

int dfs(string s){ 
	vis[s] = 1;
	if(s == t2) return 1;
	int ans = 0;
	for(int i = 0;i < s.size() - 1;i ++){
		for(int j = i;j < s.size();j ++){
			string ss;
			for(int k = i;k <= j;k ++){
				ss += s[k];
			}
			if(cg[ss].first){
				string tmp = change(s,cg[ss].second,i);
				if(vis[tmp]) continue;	
				ans += dfs(tmp);
			}
		}
	}
	return ans;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		string s1,s2;
		cin >> s1 >> s2;
		cg[s1].second = s2;
		cg[s1].first = 1;
	}
	for(int i = 1;i <= m;i ++){
		string t1;
		cin >> t1 >> t2;
		cout << dfs(t1) << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
