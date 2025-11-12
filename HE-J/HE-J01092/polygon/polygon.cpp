#include <bits/stdc++.h>
using namespace std;

int n, a[5010], ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
		
	sort(a + 1, a + n + 1);
	int ans = 0;
	if (n <= 10) {
		//3
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					int t = a[i] + a[j] + a[k];
					if (t > 2 * a[k])
						++ans;
				}
			}
		}
		if (n <= 3) {
			printf("%d\n", ans);
			return 0;
		}
		//4
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) 
				for (int k = j + 1; k <= n; k++) 
					for (int l = k + 1; l <= n; l++) {
						int t = a[i] + a[j] + a[k] + a[l];
						if (t > 2 * a[l])
							++ans;
					}
		if (n <= 4) {
			printf("%d\n", ans);
			return 0;
		}
		//5
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) 
				for (int k = j + 1; k <= n; k++) 
					for (int l = k + 1; l <= n; l++) 
						for (int w = l + 1; w <= n; w++) {
							int t = a[i] + a[j] + a[k] + a[l] + a[w];
							if (t > 2 * a[w])
								++ans;
						}
		if (n <= 5){
			printf("%d\n", ans);
			return 0;
		}
		//6
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) 
				for (int k = j + 1; k <= n; k++) 
					for (int l = k + 1; l <= n; l++) 
						for (int w = l + 1; w <= n; w++)
							for (int e = w + 1; e <= n; e++) {
								int t = a[i] + a[j] + a[k] + a[l] + a[w] + a[e];
								if (t > 2 * a[e])
									++ans;
							}	
		if (n <= 6) {
			printf("%d\n", ans);
			return 0;
		}					
		//7
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) 
				for (int k = j + 1; k <= n; k++) 
					for (int l = k + 1; l <= n; l++) 
						for (int w = l + 1; w <= n; w++)
							for (int e = w + 1; e <= n; e++)
								for (int r = e + 1; r <= n; r++) {
									int t = a[i] + a[j] + a[k] + a[l] + a[w] + a[e] + a[r];
									if (t > 2 * a[r])
										++ans;
								}	
		if (n <= 7) {
			printf("%d\n", ans);
			return 0;
		}				
		//8
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) 
				for (int k = j + 1; k <= n; k++) 
					for (int l = k + 1; l <= n; l++) 
						for (int w = l + 1; w <= n; w++)
							for (int e = w + 1; e <= n; e++)
								for (int r = e + 1; r <= n; r++)
									for (int t = r + 1; t <= n; t++) {
										int x = a[i] + a[j] + a[k] + a[l] + a[w] + a[e] + a[r] + a[t];
										if (x > 2 * a[t])
											++ans;
									}	
		if (n <= 8) {
			printf("%d\n", ans);
			return 0;
		}
		
		//9
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) 
				for (int k = j + 1; k <= n; k++) 
					for (int l = k + 1; l <= n; l++) 
						for (int w = l + 1; w <= n; w++)
							for (int e = w + 1; e <= n; e++)
								for (int r = e + 1; r <= n; r++)
									for (int t = r + 1; t <= n; t++) 
										for (int y = t + 1; y <= n; y++) {
											int x = a[i] + a[j] + a[k] + a[l] + a[w] + a[e] + a[r] + a[t] + a[y];
											if (x > 2 * a[y])
												++ans;
										}	
		if (n <= 9) {
			printf("%d\n", ans);
			return 0;
		}
		//10
		if (a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[9] + a[10] > 2 * a[10]) 
			++ans;
		printf("%d\n", ans);
	}
	return 0;
}
