#include <bits/stdc++.h>
using namespace std;

struct Tuple {
	string from;
	string to;
};

istream& operator>>(istream& in, Tuple t) {
	in >> t.from >> t.to;
	return in;
}

int main () {
	ifstream fin("replace.in");
	#ifdef DEBUG
	ostream& fout = cout;
	#else
	ofstream fout("replace.out");
	#endif
	
	int n,q;
	fin >> n >> q;
	
	vector<Tuple> rs_list;
	vector<Tuple> qs_list;
	
	for (int i = 0; i < n; ++i) {
		Tuple t;
		fin >> t;
		rs_list.push_back(t);
	}
	for (int i = 0; i < q; ++i) {
		Tuple t;
		fin >> t;
		qs_list.push_back(t);
		for (auto iter = rs_list.begin(); iter!=rs_list.end(); ++iter) {
			for (auto fs_iter = t.from.begin(); iter!=t.from.end(); ++iter) {
				std::replace(iter, fs_iter);
			}
		}
	}
	
	fin.close();
	#ifndef DEBUG
	fcout.close();
	#endif
	
	return 0;
}
