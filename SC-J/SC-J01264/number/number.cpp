#include<bits/stdc++.h>
using namespace std;

ifstream fin("number.in");
ofstream fout("number.out");
#define cin fin
#define cout fout

vector<int> all;

signed main(){
	string s; cin>>s;
	for(char c:s){
		if(isdigit(c)){
			all.push_back(c-'0');
		}
	}
	sort(all.begin(),all.end(),greater<int>());
	for(int a:all) cout<<a;
	cout<<"\n";
	return 0;
}

struct Code{
	Code(){ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); }
	~Code(){ cout.flush(),fin.close(),fout.close(); }
} wtl;