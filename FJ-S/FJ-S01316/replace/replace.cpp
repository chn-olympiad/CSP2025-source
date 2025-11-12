# include <iostream>
# include <algorithm>
# include <vector>
# include <string>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::sort;

void open() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
}

struct group{
	string s;
	string s1;
};

group* grp = 0;
int n = 0, q = 0;

void findways() {
	string ss = "", ss1 = "";
	cin >> ss >> ss1;
	
	int count = 0;
	
	for(int i = 0; i < n; i++) {
		int lastidx = 0;
		while((lastidx = ss.find(grp[i].s, lastidx)) != string::npos) {
			string backup = ss;
			if(backup.replace(lastidx, grp[i].s.size(), grp[i].s1) == ss1) {
				count++;
			}
			lastidx++;
		}
	}
	
	printf("%d\n", count);
}

int main() {
	open();
	scanf("%d %d", &n, &q);
	grp = new group[n];
	for(int i = 0; i < n; i++) {
		group g;
		cin >> g.s >> g.s1;
		grp[i] = g;
	}
	
	for(int i = 0; i < q; i++) {
		findways();
	}
}

// ____FJ-S01316____
//  Andrew M. Pines
