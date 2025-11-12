#include <bits/stdc++.h>
#define N 100005
//#define int long long
using namespace std;
inline int read(){
	int res = 0, f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		res = (res << 3) + (res << 1) + (ch ^ 48);
		ch = getchar();
	}
	return (f > 0 ? res : -res);
} 

int main(){
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout); 
	
	
	return 0;
}
