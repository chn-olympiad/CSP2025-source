#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define pss pair<string, string>
using namespace std;
const int N = 2e5 + 5, M = 5e6 + 5;

struct node{
	int s[27][27];
	int sum;
}t[M];

struct O{
	int u, l, r;
};

int n, q, m, tot;
map<pss, int> mp;
vector<int> a[N];

pss que[N];

void bld(int p){
	for(auto x : a[p]){
		string s1 = que[x].first, s2 = que[x].second;
//		cout<<s1<<" "<<s2<<"\n";
		int len = s1.size();
		int l = 0, r = len - 1;
		while(l + 1 < len && s1[l + 1] == s2[l + 1])	l++;
		while(r - 1 >= 0 && s1[r - 1] == s2[r - 1])	r--;
		if(s1[l] != s2[l])	l--;
		if(s1[r] != s2[r])	r++;
		int u = p;
		while(true){
//			cout<<u<<'\n';
//			t[u].sum++;
			int r1 = 0, r2 = 0;
			if(l >= 0)	r1 = s1[l] - 'a' + 1;
			if(r < len)	r2 = s1[r] - 'a' + 1;
//			cout<<r1<<" "<<r2<<'\n';
			if(r1 == 0 && r2 == 0){
				t[u].sum++;
				break;
			}
			if(!t[u].s[r1][r2])	t[u].s[r1][r2] = ++tot;
			l--, r++;
			u = t[u].s[r1][r2];
		}
	}
//	cout<<"---------\n";
}

//int dfs(string s, int u, int l, int r){
//	int s = t[u].sum, len = s.size();
//	int r1 = 0, r2 = 0;
//	if(l >= 0)	r1 = s[l] - 'a' + 1;
//	if(r < len)	r2 = s[r] - 'a' + 1;
//	if(r1 == 0 && r2 == 0)	return 0;
//	if(!)
//	s += dfs(s, t[])
//}

int get(string s1, string s2){
	int len = s1.size();
	int l = 0, r = len - 1;
	while(l < len && s1[l] == s2[l])	l++;
	while(r >= 0 && s1[r] == s2[r])	r--;
	string ts1 =  s1.substr(l, r - l + 1), ts2 = s2.substr(l, r - l + 1);
//	cout<<ts1<<" "<<ts2<<'\n';
	int u = mp[{ts1, ts2}];// rt
//	cout<<u<<" u\n";
	l--, r++;
	
//	return dfs(s1, u, l, r);
	
	int res = 0;
	queue<O> q;
	q.push({u, l, r});
//	q.push({u, l, len});
//	q.push({u, -1, r});
	while(!q.empty()){
		int u = q.front().u, l = q.front().l, r = q.front().r;	q.pop();
		res += t[u].sum;
		int r1 = 0, r2 = 0;
		if(l >= 0)	r1 = s1[l] - 'a' + 1;
		if(r < len)	r2 = s1[r] - 'a' + 1;
		if(r1 == 0 && r2 == 0)	continue;
//		if(!t[u].s[r1][r2])	continue;
		l--, r++;
		if(t[u].s[r1][r2])	q.push({t[u].s[r1][r2], l, r});
		if(r1 > 0 && r2 > 0){
			if(t[u].s[r1][0])	q.push({t[u].s[r1][0], l, len + 1});
			if(t[u].s[0][r2])	q.push({t[u].s[0][r2], -1, r});
		}
//		u = t[u].s[r1][r2];
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	freopen("out.txt", "w", stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		string s1, s2;	cin>>s1>>s2;
		que[i] = {s1, s2};
		int len = s1.size();
		int l = 0, r = len - 1;
		while(l < len && s1[l] == s2[l])	l++;
		while(r >= 0 && s1[r] == s2[r])	r--;
		if(l == len || r < 0)	mp[{"", ""}]++;
		else{
			s1 = s1.substr(l, r - l + 1);
			s2 = s2.substr(l, r - l + 1);
			if(!mp[{s1, s2}])	mp[{s1, s2}] = ++m;
			a[mp[{s1, s2}]].pb(i);
		}
	}
	
	tot = m;
//	cout<<m<<'\n';
	for(int i = 1;i <= m;i++)	bld(i);
	
	while(q--){
		string s1, s2;	cin>>s1>>s2;
		if(s1.size() != s2.size()){
			cout<<"0\n";
			continue;
		}
		int len = s1.size();
		int l = 0, r = len - 1;
		while(l < len && s1[l] == s2[l])	l++;
		while(r >= 0 && s1[r] == s2[r])	r--;
		if(l == len || r < 0){
			cout<<mp[{"", ""}]<<'\n';
			continue;
		}
		else{
//			s1 = s1.substr(l, r - l + 1);
//			s2 = s2.substr(l, r - l + 1);
//			cout<<s1<<" "<<s2<<'\n';
			cout<<get(s1, s2)<<'\n';
		}
	}
	return 0;
}

