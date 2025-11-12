#include<bits/stdc++.h>
using namespace std;

inline int ceils(double x) {
	if(x > int(x)) return int(x) + 1;
	else return int(x);
}

template<typename T>
inline void read(T &x) {
	x = 0;
	bool flag = 0;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') flag = !flag;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}

	if(flag)x = -x;
}

template<typename T>
inline void write(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m;
	read(n);
	read(m);
	vector<int> marks(n * m + 1, 0);
	
	int now_marks;
	read(now_marks);
	
	for(int i = 2; i <= n * m; i++) {
		read(marks[i]);
	}
	
	sort(marks.begin() + 2, marks.end(), cmp);
	int num = 0;
	for(int i = 1; i < n * m; i++) {
		if(marks[i + 1] < now_marks) {
			num = i;
			break;
		}
	}
	if(num == 0)
		num = n * m;
	int calc = ceils(double(num / (n * 1.0)));
	int count = num % m;
	if(count == 0)
		count += m;
	if(calc & 1) {
		write(calc);
		putchar(' ');
		write(count);
	}else {
		write(calc);
		putchar(' ');
		write(m - count + 1);
	}
	return 0;
}


