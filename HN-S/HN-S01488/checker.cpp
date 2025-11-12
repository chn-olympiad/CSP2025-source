#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> names{"club", "road","replace", "employ"};
	vector<int> tc{5, 4, 4, 5};
	
	for(int i = 0; i < names.size(); i ++) {
		string name = names[i];
		for(int j = 1; j <= tc[i]; j ++) {
			string cmds = "fc " + name + "\\" + name + "0.out " + name + "\\" + name + "0.ans";
			for(char &c : cmds)
				if(isdigit(c)) c += j;
			cout << "CMD: " << cmds << endl;
			system(cmds.c_str());
		}
	}
}
