#include<bits/stdc++.h>
using namespace std;
int n, q, ans;
struct Node{
	string si1, si2;
	int b_1, b_2;
} S[200005];
string tj1, tj2;
bool B = false, k = false;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i ++) {
		cin >> S[i].si1 >> S[i].si2;
	}
	for(int i = 0; i < S[1].si1.length(); i ++) {
		if(S[1].si1[i] == 'b') {
			B = true;
		}
	}
	if(B) {
		int b_1, b_2;
		for(int i = 1; i <= n; i ++) {
			for(int j = 0; j < S[i].si1.length(); j ++) {
				if(S[i].si1[j] == 'b') {
					S[i].b_1 = j;
				}
				if(S[i].si2[j] == 'b') {
					S[i].b_2 = j;
				}
			}
		}
	}
	while(q --) {
		cin >> tj1 >> tj2;
		if(!B) {
			ans = 0;
			for(int i = 1; i <= n; i ++) {
				if(S[i].si1 == tj1 && S[i].si2 == tj2) {
					k = true;
					ans ++;
				}
			}
			if(k) {
				printf("%d\n", ans);
			} else {
				printf("0\n");
			}
		} else {
			if(tj1.length() != tj2.length()) {
				printf("0\n");
			} else {
				int b_tj1, b_tj2;
				for(int j = 0; j < tj1.length(); j ++) {
				    if(tj1[j] == 'b') {
					   b_tj1 = j;
				    }
				    if(tj2[j] == 'b') {
				    	b_tj2 = j;
					}
			    }
			    for(int i = 1; i <= n; i ++) {
			    	if(b_tj1 - (S[i].b_1 - S[i].b_2) == b_tj2) {
			    		if(b_tj1+S[i].si1.length()-1-S[i].b_1 < tj1.length()) {
			    			ans ++;
						}
					}
				}
				printf("%d\n", ans);
			}	
		}
	}
	return 0;
}

