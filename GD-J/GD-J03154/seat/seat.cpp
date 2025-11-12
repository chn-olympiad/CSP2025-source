# include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
struct node{
	int num, id;
}a[110];
bool cmp(node a, node b){
	return a.num > b.num;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int r = 0, c = 1, cnt = 0;
	for(int i = 1; i <= n * m; i ++)cin >> a[i].num, a[i].id = i;
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= n * m; i ++){
		if(cnt == 0)r ++;
		else if(cnt == 1 || cnt == 3)c ++, cnt ++;
		else if(cnt == 2)r --;
		if((r == m && cnt == 0) || (r == 1 && cnt == 2))cnt ++;
		if(cnt == 4)cnt = 0;
		if(a[i].id == 1)break;
	}
	cout << c << ' ' << r;
	return 0;
}
