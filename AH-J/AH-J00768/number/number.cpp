#include<bits/stdc++.h>

using namespace std;

char s[1000011];
int a[11];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(a,0,sizeof(a));
    scanf("%s",s + 1);
    int l = strlen(s + 1);
    for(int i = 1; i <= l; i++){
        int n = s[i] - '0';
        if(0 <= n && n <= 9){
            a[n]++;
        }
    }
    for(int i = 9; i >= 0; i--){
        for(int j = 1;j <= a[i]; j++){
            printf("%d",i);
        }
    }
    return 0;
}
