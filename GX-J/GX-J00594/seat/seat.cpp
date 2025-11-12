#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
int N, xr;
int a[105];
bool cmp(int a, int b){
	return a > b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
   
    N = n*m;
    for (int i=1; i<=N; i++) {
		scanf("%d", &a[i]);
	}
	xr = a[1];
	sort(a+1, a+N+1, cmp);

	int index = 0;
	for(int i=1; i<=N; i++){
		if (a[i] == xr){
			index = i;
		}
	}
	
	int x = index / n;
	int y = index % n;
	if (y != 0) x++;
	else y = n;
	if (x%2 == 0) y = n+1-y;
	
	cout << x <<" "<< y;
    return 0;
}

