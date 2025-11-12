#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;
int num[maxn];

bool compare(int a , int b){
    return a > b;
}

int Find(int a , int n , int num[]){
    for (int i = 1 ; i <= n ; i += 1){
        if (num[i] == a){
            return i;
        }
    }
    return 0;
}

int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    int n , m;
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n * m ; i += 1){
        scanf("%d" , &num[i]);
    }
    int tmp = num[1];
    sort(num + 1 , num + (n * m) + 1 , compare);
    int P = Find(tmp , n * m , num);
    int c = (P + n - 1) / n , r;
    if (c % 2 == 0){
        int first = c * n;
        r = first - P + 1;
    }
    else{
        int first = (c - 1) * n + 1;
        r = P - first + 1;
    }
    printf("%d %d" , c , r);
    return 0;
}
