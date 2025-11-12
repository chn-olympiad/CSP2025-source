#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[105];

bool comp(const int& si, const int& sj){
    return si > sj;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d %d",&n, &m);
    for (int i = 0; i < n*m; i++)
        scanf("%d",&a[i]);
    int g = a[0];
    sort(a, a+n*m, comp);
    int i = 0, j = 0, t = 0, x = 0;
    while (a[x] != g){
        if (t == 0 && i < n-1)  i++;
        else if (t == 1 && i > 0) i--;
        else if (i == n-1 || i == 0)  j++, t ^= 1;
        x++;
        //printf("%d %d %d\n", i, j, a[x]);
    }
    printf("%d %d", j+1, i+1);
    return 0;
}

