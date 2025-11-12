#include <bits/stdc++.h>
using namespace std;

struct member{
	int a1;
	int a2;
	int a3;
	int choose{0};
};
struct club {
	vector<member> members;
};

istream& operator>>(istream& in, member m) {
	in >> m.a1 >> m.a2 >> m.a3;
	return in;
}

istream& operator>>(istream& in, club c) {
	int n;
	in >> n;
	for (int i = 0; i < n; ++i) {
		mumber a;
		in >> a;
		c.members.push_back(a);
	}
	return in;
}

int main() {
	ifstream fin("club.in");
	#ifdef DEBUG
	ostream& fout = cout;
	#else
	ofstream fout("club.out");
	#endif
	
	int t;
	fin >> t;
	
	for (int i = 0; i < t; ++i){
		club c;
		fin >> c;
		for (auto iter = c.members.begin(); iter != c.members.end(); ++iter) {
			++(iter->choose);
		}
	}
	
	// n %2=0
	// a_ij i\in[1..n] j\in[1..3]
	// d_i\in{1,2,3}
	// \forall d_i <= n/2
	
	fin.close();
	#ifndef DEBUG
	fcout.close();
	#endif
	// Ren5Jie4Di4Ling5%
	return 0;
}
