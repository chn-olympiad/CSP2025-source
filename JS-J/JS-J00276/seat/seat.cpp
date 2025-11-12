#include<bits/stdc++.h>
using namespace std;
int n, m;
int num[105];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int s;
	scanf("%d", &s);
	num[1] = s;
	int cnt = n * m;
	for(int i = 2; i <= cnt; i++){
		scanf("%d", &num[i]);
	}
	sort(num + 1, num + 1 + cnt, greater<int>());
	int t;
	for(int i = 1; i <= cnt; i++) {
		if(num[i] == s){
			t = i;
			break;
		}
	}
	int x = t % n;
	int y = t / n;
	int c;
	if(x != 0)
		y++;
	else 
		x = n;
	if(y % 2 == 0)
		c = n - x + 1;
	else
		c = x;
	printf("%d %d", y, c);
	return 0;
}
