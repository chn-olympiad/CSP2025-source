#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s1[N], s2[N], s3[N], s4[N];
string c1, c2;
string t1, t2, t3, t4;
int n, q, ans;
int read() {
	int x = 0, flag = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') flag = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * flag;
}
void write(int x) {
	if(x < 0) x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read();
	q = read();
	for(int i = 1; i <= n; i++) {
		char ch;
		cin >> c1;
		int len = c1.size();
		//cout << len << endl;
		int p = 1;
		ch = getchar();
		for(int j = 0; j < len; j++) {
			ch = getchar();
			//cout << ch;
			if(p == 3) {
				if(ch != c1[j]) {
					s2[i] = s2[i] + s4[i] + c1[j];
					s3[i] = s3[i] + s4[i] + ch;
					p = 2;
					s4[i].clear();
				}
				else s4[i] += ch;
			}
			else if(p == 2) {
				if(ch == c1[j]) p = 3, s4[i] += ch;
				else s2[i] += c1[j], s3[i] += ch;
			}
			else if(p == 1) {
				if(ch == c1[j]) s1[i] += ch;
				else p = 2, s2[i] += c1[j], s3[i] += ch; 
			}
		}
		//cout << s1[i] << ' ' << s2[i] << ' ' << s3[i] << ' ' << s4[i] << endl;
		//cout << endl;
	}
	while(q--) {
		cin >> c1 >> c2;
		if(c1.size() != c2.size()) {
			puts("0");
			continue;
		}
		t1.clear();
		t2.clear();
		t3.clear();
		t4.clear();
		ans = 0;
		int len = c1.size();
		int p = 1;
		for(int j = 0; j < len; j++) {
			if(p == 3) {
				if(c2[j] != c1[j]) {
					t2 = t2 + t4 + c1[j];
					t2 = t2 + t4 + c2[j];
					p = 2;
					t4.clear();
				}
				else t4 += c1[j];
			}
			else if(p == 2) {
				if(c2[j] == c1[j]) p = 3, t4 += c1[j];
				else t2 += c1[j], t3 += c2[j];
			}
			else if(p == 1) {
				if(c2[j] == c1[j]) t1 += c2[j];
				else p = 2, t2 += c1[j], t3 += c2[j]; 
			}
		}
		//cout << t1 << ' ' << t2 << ' ' << t3 << ' ' << t4 << endl;
		char ch1 = t1[t1.size() - 1], ch2 = t4[0];
		//cout << ch1 << ' ' << ch2 << endl;
		int l = 0, r = t3.size() - 1;
		string t5;
		t5.clear();
		if(t2[r] == ch2 && t3[l] == ch1) swap(t2, t3);
		if(t2[l] == ch1 && t3[r] == ch2) {
			//cout << t2 << ' ' << t3 << endl;
			int j = 0;
			while(t2[j] != t3[l]) j++;
			while(j <= r && t2[j] == t3[l]) t5 += t2[j], j++, l++; 
		}
		
		
		//cout << t5 << endl;
		for(int i = 1; i <= n; i++) {
			if(((t2 == s2[i] && t3 == s3[i]) || t5 == s2[i])) {
				int lt1 = t1.size(), lt4 = t4.size();
				int ls1 = s1[i].size(), ls4 = s4[i].size();
				if(lt1 >= ls1 && lt4 >= ls4) {
					bool pd = 1;
					int d = lt1 - ls1;
					for(int j = d; j < lt1; j++) if(s1[i][j - d] != t1[j]) {pd = 0; break;}
					if(pd == 1) {
						int lenth = s4[i].size();
						for(int j = 0; j < lenth; j++) if(s4[i][j] != t4[j]) {pd = 0; break;}
						if(pd == 1) ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
