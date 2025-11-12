#include<bits/stdc++.h>
using namespace std;
int n, m, r;
int a[105], b[15][15];
int cmp(int x, int y){
	int a = x, b = y;
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + m * n + 1, cmp);
	int l = 1, h = 1, t = 1;
	while(t <= m * n){
				
		if(a[t] == r)
		{
			cout << l << " " << h;
			break;
		}

		if(l % 2 == 1)
		{
			if(h + 1 > n) l++;
			else h++;
		}
		else{
			if(h - 1 < 1) l++;
			else h--;
		} 
		t++;
		
	}
	
	return 0;
} 