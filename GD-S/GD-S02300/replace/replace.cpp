#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5+5;

string a,b;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n,q;
	map<int,vector<int>> seq;
	set<int> opted;
	cin>>n>>q;
	for (int i=0;i<n;i++){
		cin>>a>>b;
		int f,s;
		for (int j=0;j<(int) a.size();j++){
			if (a[j] == 'b') f = j;
			if (b[j] == 'b') s = j;
		}
		seq[f-s].push_back(a.size());
		opted.insert(f-s);
	}
	
	for (int i:opted) sort(seq[i].begin(),seq[i].end());
	
	for (int i=0;i<q;i++){
		cin>>a>>b;
		if (a.size() != b.size()){
			cout<<0<<'\n';
			continue;
		}
		int f,s;
		for (int j=0;j<(int) a.size();j++){
			if (a[j] == 'b') f = j;
			if (b[j] == 'b') s = j;
		}
		
		vector<int>& oof = seq[f-s];
		auto it = upper_bound(oof.begin(),oof.end(), a.size());
		int foo = it-oof.begin();
		cout<<foo<<'\n';
	}
	
	return 0; 
}
/*
4 2
ba ab
aba
aab
abaa
aaba
aaaaaaaaaba
aaaaaaaaaab
aabaa
aaaba
aaba
aaaba
*/
