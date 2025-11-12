#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, k;
	cin >> n >> m;
	k = n * m;
	int s[101];
	int N;  //小R 
	for(int i = 1; i <= k; i++){
		cin >> s[i];
		if(i == 1)
			N = s[i];
	}
	int a1 = 1, a2 = 1;
	sort(s + 1, s + k + 1, cmp);
	for(int i = 1; i <= k; i++){
		if(s[i] == N){
			cout << a1 << ' ' << a2;
			break;
		}
		else{
			if(a1 % 2 == 1){
				a2++;
				if(a2 > n){
					a2 --;
					a1++;
				}
			}
			else if(a1 % 2 == 0){
				a2--;
				if(a2 < 1){
					a2++;
					a1++;
				}
			}

		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}