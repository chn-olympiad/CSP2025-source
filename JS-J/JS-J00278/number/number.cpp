#include <bits/stdc++.h>
using namespace std;
int idx = 1, cnt[10];
char s[1000050];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s + 1);
    while(s[idx] != '\0'){
        if(s[idx] >= '0' && s[idx] <= '9') cnt[s[idx] - '0']++;
        idx++;
    }
    for(int i = 9 ; i >= 0 ; --i)
        for(int j = 1 ; j <= cnt[i] ; ++j)
            printf("%d", i);
    printf("\n");
    fclose(stdin);
    fclose(stdout);
}
