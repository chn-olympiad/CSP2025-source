#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100100;
ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
void write(ll x){
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x <= 9){
		putchar(x + '0');
		return;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}

int n;
int a[N][4], b[N];

void solve(){
	n = read();
	for (int i = 1; i <= n; i++)
		a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
	int x = 0, y = 0, z = 0;
	ll sum = 0;
	for (int i = 1; i <= n; i++){
		if(a[i][1] == max({a[i][1], a[i][2], a[i][3]})){
			x++;
			sum += a[i][1];
			b[i] = 1;
		}else if(a[i][2] == max({a[i][1], a[i][2], a[i][3]})){
			y++;
			sum += a[i][2];
			b[i] = 2;
		}else{
			z++;
			sum += a[i][3];
			b[i] = 3;
		}
	}
	int t = 0, d = 0;
	if(x > n / 2)
		t = 1, d = x - n / 2;
	else if(y > n / 2)
		t = 2, d = y - n / 2;
	else if(z > n / 2)
		t = 3, d = z - n / 2;
	if(t == 0){
		write(sum);
		puts("");
		return;
	}
	map<int, int> s;
	for (int i = 1; i <= n; i++){
		if(b[i] == t){
			if(t == 1){
				s[a[i][1] - max(a[i][2], a[i][3])]++;
			}else if(t == 2){
				s[a[i][2] - max(a[i][1], a[i][3])]++;
			}else{
				s[a[i][3] - max(a[i][1], a[i][2])]++;
			}
		}
	}
	auto it = s.begin();
	for (int i = 1; i <= d; i++, it++){
		int a = it->first, b = it->second;
		if(i + b - 1 <= d){
			i += b - 1;
			sum -= b * a;
		}else{
			sum -= (d - i + 1) * a;
			break;
		}
	}
	write(sum);
	puts("");
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while(T--){
		solve();
	}
	return 0;
}
