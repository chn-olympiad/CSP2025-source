#include<bits/stdc++.h>
using namespace std;
int x, y, sx, sy;
int a[1005], b[1005];
int main(){
	cin >> x >> y;
	for(int i = 1; i <= x * y; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a + 1, a + x * y + 1);
	int r;
	for (int i = 1; i <= x * y; i++)
	{
		if(a[i] == b[1]){
			r = i;
		}
	}
	int k = x * y;
	for (int i = 1; i <= x * y; i++)
	{
		a[i] = k;
		k--;
	}
	int t = lower_bound(a + 1, a + x * y + 1, r) - a - 1;
	t++;
	int sx = t / x + 1;
	if (t % x == 0){
		sx--;
	}
	if(sx % 2 == 1){
		sy = t - x * (sx - 1); //t = 1, lie = 1
	}
	else{
		sy = x - (t - x * (sx - 1)) + 1;
	}
	cout << sx << " " << sy;
	return 0;
}
