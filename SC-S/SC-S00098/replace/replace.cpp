#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_map>
#include <vector>

using namespace std;

typedef unsigned long long ull;

const int N = 2e5 + 10, MOD = 131;

string str[N][2];
int n, q, l[N], r[N];
unordered_map<int, vector<int>> m;

void init(){
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> str[i][0] >> str[i][1];
		int l2 = 0;
		while(str[i][0][l[i]] != 'a') l[i]++;
		while(str[i][1][l2] != 'a') l2++;
		m[l2 - l[i]].push_back(i);
		r[i] = str[i][0].length() - l[i];
	}
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	init();
	string t1, t2;
	while(q--){
		cin >> t1 >> t2;
		int l1 = 0, l2 = 0, res = 0;
		while(t1[l1] != 'a') l1++;
		while(t2[l2] != 'a') l2++;
		if(!m[l2 - l1].empty()){
			for(int i = 0; i < (int)m[l2 - l1].size(); i++){
				if(l1 - l[m[l2 - l1][i]] >= 0 && l1 + r[m[l2 - l1][i]] < t1.length()) res++;
			}
		}
		printf("%d\n", res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}