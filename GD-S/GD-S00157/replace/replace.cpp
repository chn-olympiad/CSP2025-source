#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50,M = 5e6 + 50;
int read(){
	int a = 1,x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') a = -1;
		ch = getchar();
	} 
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return a * x;
}
vector<int> nxts[N][3],nxtt[3];
string s[N][3];
bool b[M];
void get(string s,vector<int> &nxt){
	assert(nxt.empty());
	nxt.push_back(0);
	nxt.push_back(0);
	int p;
	for(int i=2;i<s.size();i++){
		p = nxt[i - 1];
		while(p && s[i] != s[p + 1]) p = nxt[p];
		if(s[i] == s[p + 1]) nxt.push_back(p + 1);
		else nxt.push_back(0); 
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	clock_t bg = clock();
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		s[i][1] = " " + s[i][1],s[i][2] = " " + s[i][2];
		get(s[i][1],nxts[i][1]),
		get(s[i][2],nxts[i][2]);
	}
//	cerr<<"OK\n";
	while(q--){
//		cerr<<q<<'\n';
		string t[3];
		cin>>t[1]>>t[2];
		int m = t[1].size();
		t[1] = " " + t[1],t[2] = " " + t[2];
		int pre = 1,suf = m;
		while(t[1][pre] == t[2][pre]) pre++;
		while(t[1][suf] == t[2][suf]) suf--;
//		cerr<<pre<<" "<<suf<<'\n';
		int res = 0;
		for(int i=1;i<=n;i++){
			int p = 0,p2 = 0;
			for(int j=1;j<=m;j++){
//				cerr<<j<<'\n';
				while(p && s[i][1][p + 1] != t[1][j]) p = nxts[i][1][p];
				if(s[i][1][p + 1] == t[1][j]) p++;
				while(p2 && s[i][2][p2 + 1] != t[2][j]) p2 = nxts[i][2][p2];
				if(s[i][2][p2 + 1] == t[2][j]) p2++;
				if(p2 + 1 == s[i][2].size() && p + 1 == s[i][1].size() && j >= suf && j - p + 1 <= pre){
					res++;
				}
				if(p2 + 1 == s[i][2].size()){
					p2 = nxts[i][2][p2];
				}
				if(p + 1 == s[i][1].size()){
					p = nxts[i][1][p];
				}
			}
		}
		cout<<res<<'\n';
//		cout<<res;
//		if(q % 10 == 0) cout<<endl;
//		else cout<<'\n';
	}
	clock_t ed = clock();
//	cerr<<'\n'<<double(ed - bg) / CLOCKS_PER_SEC;
	return 0;
}
