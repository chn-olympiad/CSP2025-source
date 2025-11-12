#include<bits/stdc++.h>
using namespace std;

struct D{
	int a1, a2, a3;
};
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t, n, inc[100001], a1[100001], k, p1, p2, p3, ans, l = 0;
	D d[100001];
	cin >> t;
	for(int p = 0; p < t; p++){
		cin >> n;
		ans = 0;
		for(int i = 0; i < n; i++){
			cin >> d[i].a1 >> d[i].a2 >> d[i].a3;
			a1[i] = d[i].a1;
			inc[i] = abs(d[i].a1 - d[i].a2) + abs(d[i].a1 - d[i].a3) + abs(d[i].a2 - d[i].a3);
			if(!(d[i].a2 == d[i].a3 && d[i].a2 == 0)) l = 1;
		}
		for(int i = 0; i < n; i++){
			k = i;
			for(int j = i + 1; j < n; j++){
				if(inc[k] > inc[j]){
					swap(inc[k], inc[j]);
					swap(d[k], d[j]);
					k = j;
				}
			}
		}
		if(l == 1){
			p1 = p2 = p3 = 0;
			for(int i = 0; i < n; i++){
				if(p1 == n / 2){
					if(d[i].a2 >= d[i].a3){
						ans += d[i].a2;
						p2 ++;
					}
					else if(d[i].a2 < d[i].a3){
						ans += d[i].a3;
						p3 ++;
					}
				}
				else if(p2 == n / 2){
					if(d[i].a1 >= d[i].a3){
						ans += d[i].a1;
						p1 ++;
					}
					else if(d[i].a1 < d[i].a3){
						ans += d[i].a3;
						p3 ++;
					}
				}
				else if(p3 == n / 2){
					if(d[i].a1 >= d[i].a2){
						ans += d[i].a1;
						p1 ++;
					}
					else if(d[i].a1 < d[i].a2){
						ans += d[i].a2;
						p2 ++;
					}
				}
				else{
					if(d[i].a1 >= d[i].a2){
						if(d[i].a1 >= d[i].a3){
							ans += d[i].a1;
							p1 ++;
						}
						else if(d[i].a1 < d[i].a3){
							ans += d[i].a3;
							p3 ++;
						}
					}
					else if(d[i].a2 >= d[i].a3){
						if(d[i].a2 >= d[i].a1){
							ans += d[i].a2;
							p2 ++;
						}
						else if(d[i].a2 < d[i].a1){
							ans += d[i].a1;
							p1 ++;
						}
					}
					else if(d[i].a1 >= d[i].a3){
						if(d[i].a1 >= d[i].a2){
							ans += d[i].a1;
							p1 ++;
						}
						else if(d[i].a1 < d[i].a2){
							ans += d[i].a2;
							p2 ++;
						}
					}
				}
			}
		}
		else if(l == 0){
			sort(a1, a1 + n);
			for(int i = n - 1; i >= n / 2; i--) ans += a1[i];
		}
		cout << ans << endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
