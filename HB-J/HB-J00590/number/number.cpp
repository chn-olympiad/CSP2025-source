#include<cstdio>
int num[10];
char t;
bool fy;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    while(~(t=getchar())) if('0'<=t && t<='9') ++num[t-'0'];
    for(int i=9; i; --i){
        if(num[i]) fy=true;
        while(num[i]--) putchar(i+'0');
    }
    if(fy) while(num[0]--) putchar('0');
    else putchar('0');
    return 0;
}
