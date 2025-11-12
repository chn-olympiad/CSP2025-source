#include <bits/stdc++.h>
using namespace std;

string sa[200010], sb[200010];

int main()
{
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i<=n; i++) {
		int st, ed;
		st = ed = 0;
		string s1, s2;
		cin >> s1 >> s2;
		for(int j = 0; j<s1.size(); j++) {
			if(s1[j] != s2[j]) {
				st = j;
				break;
			}
		}
		for(int j = s1.size()-1; j>=0; j--) {
			if(s1[j] != s2[j]) {
				ed = j;
				break;
			}
		}
//		for(int j = st; j<=ed; j++) {
//			sa[i][j] = s1[j];
//			sb[i][j] = s2[j];
//		}
		if(ed <= st) break;
//		sa[i] = s1.substr(st-1, ed-st+1);
//		sb[i] = s2.substr(st-1, ed-st+1);
		int cnt;
		cnt = 0;
		for(int j = st; j<=ed; j++) {
			sa[i][cnt] = s1[j];
			sb[i][cnt++] = s2[j];
		}
	}
	while(q--) {
		string s1, s2, s3, s4;
		cin >> s1 >> s2;
		int st, ed;
		st = ed = 0;
		for(int i = 0; i<s1.size(); i++) {
			if(s1[i] != s2[i]) {
				st = i;
				break;
			}
		}
		for(int i = s1.size()-1; i>=0; i--) {
			if(s1[i] != s2[i]) {
				ed = i;
				break;
			}
		}
		int cnt = 0;
		for(int j = st; j<=ed; j++) {
			s3[cnt] = s1[j];
			s4[cnt++] = s2[j];
		}
		int cnt1 = 0;
		for(int i = 1; i<=n; i++) {
			cout << sa[i] <<" "<< s3 <<" "<< sb[i] <<" "<< s4<<endl;
			if(sa[i] == s3 and sb[i] == s4) cnt1++;
		}
		cout << cnt1 << endl;
	}
	return 0;
}
