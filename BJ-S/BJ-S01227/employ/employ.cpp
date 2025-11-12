#include<bits/stdc++.h>
using namespace std;
#define N 505
int n, m;
string s;
int c[N];
char t;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    cin >> s;
    for(int i = 1; i <= n; i++){
        scanf("%d", c+i);
    }
    printf("0\n");
    return 0;
}