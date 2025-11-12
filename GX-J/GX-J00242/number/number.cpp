#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s);
    int j = 0, len = strlen(s);
    bool abc = true;
    for(int i = 0; i < len; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            s[j++] = s[i];
            if(s[i] != 0) abc = false;
        }
    }
    if(abc){
        printf("0");
        return 0;
    }
    sort(s, s + j);
    for(int i = j-1; i >= 0; i--){
        printf("%c", s[i]);
    }
    return 0;
}
