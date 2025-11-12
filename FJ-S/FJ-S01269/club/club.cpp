#include <bits/stdc++.h>
#define N 100005
//#define int long long
using namespace std;
inline long long read(){
	long long res = 0, f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		res = (res << 3) + (res << 1) + (ch ^ 48);
		ch = getchar();
	}
	return (f > 0 ? res : -res);
} 
struct node{
	long long a, b, c;
}d[N];
priority_queue<long long> q1;
int main(){
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout); 
	long long T = read();
	S:
	while (T--) {
		long long n = read();
		long long cnt1, cnt2, cnt3;
		long long ans = 0;
		cnt1 = cnt2 = cnt3 = 0;
		vector<long long> aa, bb, cc;
		for (int i = 1; i <= n; i++){
			d[i].a = read(), d[i].b = read(), d[i].c = read();
			long long a = d[i].a, b = d[i].b, c = d[i].c;
			if (cnt1 == min(min(cnt1, cnt2), cnt3)){
				if (a == max(max(a, b), c)) {
					cnt1++;
					ans += a;
					aa.push_back(i);
				}
				else if (b == max(max(a, b), c)) {
					cnt2++;
					ans += b;
					bb.push_back(i);
				}
				else if (c == max(max(a, b), c)) {
					cnt3++;
					ans += c;
					cc.push_back(i);
				}
			}
			else if (cnt2 == min(min(cnt1, cnt2), cnt3)){
				if (b == max(max(a, b), c)) {
					cnt2++;
					ans += b;
					bb.push_back(i);
				}
				else if (a == max(max(a, b), c)) {
					cnt1++;
					ans += a;
					aa.push_back(i);
				}
				else if (c == max(max(a, b), c)) {
					cnt3++;
					ans += c;
					cc.push_back(i);
				}
			}
			else if (cnt3 == min(min(cnt1, cnt2), cnt3)){
				if (c == max(max(a, b), c)) {
					cnt3++;
					ans += c;
					cc.push_back(i);
				}
				else if (a == max(max(a, b), c)) {
					cnt1++;
					ans += a;
					aa.push_back(i);
				}
				else if (b == max(max(a, b), c)) {
					cnt2++;
					ans += b;
					bb.push_back(i);
				}
			}	
		}
		if (cnt1 <= n/2 && cnt2 <= n/2 && cnt3 <= n/2) {
//			cout << 1 << " ";
			cout << ans << "\n";
			goto S;
		}
//		cout << n/2 << " " << cnt1 << " " << cnt2 << " " << cnt3 << "\n"; 
		while(!q1.empty()) q1.pop();
		if (cnt1 > n/2){
			for (auto idx : aa){
				long long a = d[idx].a, b = d[idx].b, c = d[idx].c;
				q1.push(b - a);
				q1.push(c - a);
			}
			long long tot = cnt1 - n/2;
			while(tot--) {
				long long x = q1.top();
				q1.pop();
//				cout << ans << " ";
//				cout << x << "  ";
				ans += x;
			}
//			cout << "\n";
//			cout << 2;
			cout << ans << "\n";
			goto S;
		}
		else if (cnt2 > n/2){
			for (auto idx : bb){
				long long a = d[idx].a, b = d[idx].b, c = d[idx].c;
				q1.push(a - b);
				q1.push(c - b);
			}
			long long tot = cnt2 - n/2;
			while(tot--) {
				long long x = q1.top();
				q1.pop();
//				cout << ans << " ";
//				cout << x << "  ";
				ans += x;
			}
//			cout << "\n";
//			cout << 3;
			cout << ans << "\n";
			goto S;
		}
		else if (cnt3 > n/2){
			for (auto idx : cc){
				long long a = d[idx].a, b = d[idx].b, c = d[idx].c;
				q1.push(a - c);
				q1.push(b - c);
			}
			long long tot = cnt3 - n/2;
			while(tot--) {
				long long x = q1.top();
				q1.pop();
//				cout << ans << " ";
//				cout << x << "  ";
				ans += x;
			}
//			cout << "\n";
//			cout << 4;
			cout << ans << "\n";
			goto S;
		}
	}
	
	return 0;
}
