#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
string s1[200001], s2[200001];
string substr(string s, int start, int end) {
	string as;
	for (int i=start; i<=end; i++){
		as += s[i];
	}
	return as;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i=1; i<=n; i++){
		cin >> s1[i] >> s2[i];
	}
	while (q--){
		string q1, q2;
		cin >> q1 >> q2;
		int ans = 0;
		for (int k=1; k<=n; k++){
			bool flag1 = false;
			int start = -1, end = -1;
			int len1 = s1[k].size(), len2 = q1.size();
			if (len1 > len2) continue;
			for (int i=0; i<len2; i++){
				int same = 0, si = i;
				for (int j=0; j<len1; j++){
					if (s1[k][j] != q1[si]) break;
					if (start == -1) start = j;
					same++;
					si ++;
				}
				if (same == len1) {
					end = start + len1;
					flag1 = true;
				}
			}
			if (!flag1) continue;
			
			bool flag2 = false;
			int start2 = -1, end2 = -1;
			if (len1 > len2) continue;
			for (int i=0; i<len2; i++){
				int same2 = 0, si = i;
				for (int j=0; j<len1; j++){
					if (s2[k][j] != q2[si]) break;
					if (start2 == -1) start2 = j;
					same2++;
					si ++;
				}
				if (same2 == len1) {
					end2 = start2 + len1;
					flag2 = true;
				}
			}
	
			if (flag1 && flag2) {
				if (start != start2) continue;
				string st1 = substr(q1, 0, start - 1), ed1 = substr(q1, end, len2 - 1);
				string st2 = substr(q2, 0, start2 - 1), ed2 = substr(q2, end2, len2 - 1);
				if (st1 == st2 && ed1 == ed2) {
					ans++;
					continue;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

