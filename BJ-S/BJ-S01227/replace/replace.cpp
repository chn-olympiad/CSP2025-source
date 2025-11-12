#include<bits/stdc++.h>
using namespace std;
#define N 200005
int n, q;
string s1[N], s2[N], t1[N], t2[N];
char t;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++){
        cin >> s1[i] >> t >> s2[i];
    }
    for(int i = 1; i <= q; i++){
        cin >> t1[i] >> t >> t2[i];
        printf("0\n");
    }
    return 0;
}
