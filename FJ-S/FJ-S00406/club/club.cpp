#include<bits/stdc++.h>
using namespace std;
int N[100000 + 10][3];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t --) {
		vector<int> c1, c2, c3;
		int n, sum = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; ++ i) {
			scanf("%d %d %d", &N[i][0], &N[i][1], &N[i][2]);
			int maxx = max(N[i][0], max(N[i][1], N[i][2]));
			if(maxx == N[i][0]) {
				sum += N[i][0];
				c1.push_back(i);
			} else if(maxx == N[i][1]) {
				sum += N[i][1];
				c2.push_back(i);
			} else {
				sum += N[i][2];
				c3.push_back(i);
			}
		}
		int l1 = c1.size(), l2 = c2.size(), l3 = c3.size();
		if(l1 > n / 2) {
			int ch1[100000 + 10] = {};
			int k = 0;
			for(int i = 0; i < l1; ++ i) {
				if(N[c1[i]][1] > N[c1[i]][2]) {
					ch1[k ++] = N[c1[i]][0] - N[c1[i]][1];
				} else {
					ch1[k ++] = N[c1[i]][0] - N[c1[i]][2];
				}
			}
			sort(ch1, ch1 + k);
			for(int i = 0; i < l1 - n / 2; ++ i) {
				sum = sum -  ch1[i];
			}
		} else if(l2 > n / 2) {
			int ch2[100000 + 10] = {};
			int k = 0;
			for(int i = 0; i < l2; ++ i) {
				if(N[c2[i]][0] > N[c2[i]][2]) {
					ch2[k ++] = N[c2[i]][1] - N[c2[i]][0];
				} else {
					ch2[k ++] = N[c2[i]][1] - N[c2[i]][2];
				}
			}
			sort(ch2, ch2 + k);
			for(int i = 0; i < l2 - n / 2; ++ i) {
				sum = sum - ch2[i];
			}
		} else if(l3 > n / 2) {
			int ch3[100000 + 10] = {};
			int k = 0;
			for(int i = 0; i < l3; ++ i) {
				if(N[c3[i]][0] > N[c3[i]][1]) {
					ch3[k ++] = N[c3[i]][2] - N[c3[i]][0];
				} else {
					ch3[k ++] = N[c3[i]][2] - N[c3[i]][1];
				}
			}
			sort(ch3, ch3 + k);
			for(int i = 0; i < l3 - n / 2; ++ i) {
				sum = sum - ch3[i];
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
