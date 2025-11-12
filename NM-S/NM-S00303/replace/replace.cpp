#include<bits/stdc++.h>
using namespace std;

int n, q, l_s1, l_s2, l_t1, l_t2, sum1, sum2;
char s1[5000001], s2[5000001], t1[5000001], t2[5000001];

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++){
        scanf("%s%s", s1+1, s2+1);
    }
    for(int i = 1; i <= q; i++){
        scanf("%s%s", t1+1, t2+1);
    }
    l_s1 = strlen(s1+1);
    l_s2 = strlen(s2+1);
    l_t1 = strlen(t1+1);
    l_t2 = strlen(t2+1);
    for(int i = 1; i <= l_s1; i++){
        s1[i] ^= s2[i];
    }
    for(int i = 1; i <= l_s2; i++){
        s2[i] ^= s1[i];
    }
    for(int i = 1; i <= l_t1; i++){
        t1[i] ^= t2[i];
    }
    for(int i = 1; i <= l_t2; i++){
        t2[i] ^= t1[i];
    }
    for(int i = 1; i <= l_s1; i++){
        if(s1[i] == s2[i]) continue;
    }
    for(int i = 1; i <= l_t1; i++){
        if(t1[i] == t2[i]) continue;
    }
    for(int i = 1; i <= l_s1; i++){
        if(s1[i] == s2[i]) sum1++;
        else if(s1[i] != s2[i]) sum1 +=  0;
    }
    for(int i = 1; i <= l_t1; i++){
        if(t1[i] == t2[i]) sum2++;
        else if(t1[i] != t2[i]) sum2 += 0;
    }
    for(int i = 1; i <= q; i++){
        printf("%d\n", sum1 ^ sum2);
    }
    return 0;
}
