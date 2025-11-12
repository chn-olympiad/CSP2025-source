#include<bits/stdc++.h>
using namespace std;
struct blk{
    int h, cj;
}a[101];
int n, m, x = 1, y = 1;
bool cmp(blk a, blk b){
	return a.cj > b.cj;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    int oph = n * m;
    for(int i = 1; i <= oph; i++){
        cin >> a[i].cj;
        a[i].h = i;
    }
    sort(a + 1, a + oph + 1, cmp);
    int sum = 1;
    int f = 0;
    bool flag = false;
    for(int i = 1; i <= oph; i++){
		if(a[i].h == 1){
			cout << x << ' ' << y;
			break;
		}
		if((y == 1 || y == n) && i != 1 && flag == false){
			flag = true;
			if(sum % 2 == 1){
				y = n;
				f = 1;
				x++;
				sum++;
			}
			else if(sum % 2 == 0){
				y = 1;
				f = 0;
				sum++;
				x++;
			}
			continue;
		}
		flag = false;
		if(f == 1)
			y--;
		else if(f == 0)
			y++;
	}
	return 0;
}
