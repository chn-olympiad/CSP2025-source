#include<bits/stdc++.h>
#define maxn 1000006

char s[maxn];
int use[maxn];
int idx;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        char ch = s[i];
        if(ch >= '0' && ch <= '9'){
            use[idx++] = ch - '0';
        }
    }
    std::sort(use, use + idx);
    for(int i = idx - 1; i >= 0; i--){
        printf("%d", use[i]);
    }
    puts("");

    return 0;
}
