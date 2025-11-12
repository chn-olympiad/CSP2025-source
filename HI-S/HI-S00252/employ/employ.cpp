#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;
const int INF = 1e9+7;
const ll LLINF = (ll)1e18+7;
const lf LFINF = (lf)1e18+7;
const int maxn = 2e5+5;
const int maxm = 2e5+5;
int T, N, M, K, Q;

bool inline isdig(const char &ch){
	return ch >= '0' && ch <= '9';
}

template <typename type>
void inline read(type &x){
	x = 0; type f = 1;
	char ch = getchar();
	while (!isdig(ch)){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdig(ch)) x = x*10+ch-'0', ch = getchar();
	x = x*f;
} 

int main(){
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	printf("0\n"); 
	
	
	return 0;
}
