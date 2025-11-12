#include<bits/stdc++.h>
using namespace std;
int n, m, a[105], box[105], id;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n * m; i++) scanf("%d", &a[i]), box[a[i]]++;
    for(int i = 100; i > a[1]; i--) id += box[i];
    int k = id / n;
    printf("%d ", k + 1);
    if(k & 1) printf("%d", n - id % n);
    else printf("%d", id % n + 1);
	return 0;
}

