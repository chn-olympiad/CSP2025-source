#include <bits/stdc++.h>
using namespace std;

char s[1000010];
int cnt[10];

int main(){

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s+1);
    int n=strlen(s+1);
    for(int i=1; i<=n; i++){
        if(isdigit(s[i])){
            cnt[s[i]-'0']++;
        }
    }
    for(int i=9; i>=0; i--){
        for(int j=1; j<=cnt[i]; j++){
            printf("%d", i);
        }
    }
    printf("\n");

    return 0;

}
