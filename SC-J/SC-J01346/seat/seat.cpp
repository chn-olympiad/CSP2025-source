#include<bits/stdc++.h>
using namespace std;

void setup() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w",stdout);
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	setup();
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> a;
	
	for (int i=0;i<n*m; i++) {
		int p;
		scanf("%d", &p);
		a.push_back(p);
	}
	int sr = a[0];
	sort(a.begin(), a.end(), cmp);
	vector<vector<int>> b(n, vector<int>(m, 0));
	for (int i = 0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (i % 2 == 0)
				b[i][j] = a[m*i + j];
			else
				b[i][m-j-1]=a[m*i+j];
			
		}
	}
	for (int i = 0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (b[i][j] == sr) {
				printf("%d %d", i+1, j+1);
				return 0;
			}
			
		}
	}
	
	printf("\n");
	return 0;
	
}