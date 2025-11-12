#include<bits/stdc++.h>
using namespace std;
int n, m;
struct Seat{
	int x, y, s, id;
}p[105];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int cnt = 1;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++,cnt++){
			p[cnt].x = j;
			p[cnt].y = i;
		}
		if(i+1 > m) continue;
		i++;
		for(int j = n; j >= 1; j--,cnt++){
			p[cnt].x = j;
			p[cnt].y = i;
		}
	}
	cnt--;
	for(int i = 1; i <= cnt; i++){
		cin >> p[i].s;
		p[i].id = i;
	}
	for(int i = 1; i <= cnt; i++){
		bool flag = 1;
		for(int j = cnt-1; j >= i; j--){
			if(p[j].s < p[j+1].s){
				swap(p[j].s, p[j+1].s);
				swap(p[j].id, p[j+1].id);
				flag = 0;
			}
		}
		if(flag) break;
	}
	for(int i = 1; i <= cnt; i++)
		if(p[i].id == 1){
			cout << p[i].y << ' ' << p[i].x << endl;
			break;
		}
	return 0;
}
