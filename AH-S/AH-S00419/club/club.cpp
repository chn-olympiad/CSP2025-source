#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N][3], h[N], v[N], d[N], b[3];
int read(){
	int s = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * f;
}
void write(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = read();
	while(t--){
		int n = read();
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 3; j++)
				a[i][j] = read();
		
		bool pd = 1;
		for(int i = 1; i <= n; i++)
			if(a[i][2] != 0 || a[i][3] != 0) pd = 0;
			
		if(pd == 1){
			for(int i = 1; i <= n; i++)
			{
				int x = a[i][1];
				h[i] = x;
			}
			sort(h + 1, h + n + 1);
			int sum = 0;
			for(int i = n / 2 + 1; i <= n; i++)
				sum += h[i];
			printf("%d\n", sum);
		}
		else {
			for(int i = 1; i <= n; i++){
				int x = a[i][1], y = a[i][2], z = a[i][3];
				if(x > y && y > z) v[i] = x, d[i] = y;
				else if(x > z && z > y) v[i] = x, d[i] = z;
				else if(y > x && x > z) v[i] = y, d[i] = x;
				else if(y > z && z > x) v[i] = y, d[i] = z;
				else if(z > x && x > y) v[i] = z, d[i] = x;
				else if(z > x && x > y) v[i] = z, d[i] = x;
				else v[i] = z, d[i] = y;
			}
			int sum = 0, k = n / 2;
			for(int i = 1; i <= n; i++){
				int x = a[i][1], y = a[i][2], z = a[i][3];
				if(x > y && x > z){
					if(b[1] < k) sum += x, b[1]++;
					else sum += max(v[i - 1] + d[i], v[i] + d[i - 1]);
				}
				if(y > x && y > z){
					if(b[2] < k) sum += y, b[2]++;
					else sum += max(v[i - 1] + d[i], v[i] + d[i - 1]);
				}
				if(z > x && z > y){
					if(b[3] < k) sum += z, b[3]++;
					else sum += max(v[i - 1] + d[i], v[i] + d[i - 1]);
				}
			}
			printf("%d\n", sum);	
		}
	}
	return 0;
}
