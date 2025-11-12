#include<iostream>
#include<stdio.h>

using namespace std;

char s[1000100];
int a[10];

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", s+1);
    for(int i = 1;s[i];i++){
        if('0' <= s[i] <= '9') a[s[i]-'0']++;
    }
    for(int i = 9;i >= 0;i--)
        for(;a[i]--;)
            printf("%d", i);
}
