#include<bits/stdc++.h>
#define N 500
#define M 0
#define K 0
#define INF 0
#define mod 0
#define int1 long long
using namespace std;
int1 n,m,i,ans;
int1 boom,c[N + 5];
bool s[N + 5];
int1 p[N + 5];
const int1 read(){
    int1 x = 0;
    bool f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        f ^= (ch == '-');
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return (f ? x : -x);
}
const bool ischar(const char ch,const int1 x){
    return (((x & 1) && ch >= 'A' && ch <= 'Z') || ((x & 2) && ch >= 'a' && ch <= 'z') || 
    ((x & 4) && ch >= '0' && ch <= '9') || 
    ((x & 8) && ch != ' ' && ch != '\r' && ch != '\n') || ((x & 16) && ch != '\r' && ch != '\n'));
}
const char getc(const int1 x){
    char ch = getchar();
    while(!ischar(ch,x)){
        ch = getchar();
    }
    return ch;
}
const int1 getst(char a[],int1 st,const int1 x){
    char ch = getchar();
    while(!ischar(ch,x)){
        ch = getchar();
    }
    st--;
    while(ischar(ch,x)){
        a[++st] = ch;
        ch = getchar();
    }
    return st;
}
void uprint(const int1 x){
    if(x >= 10){
        uprint(x / 10);
    }
    putchar(x % 10 ^ 48);
    return ;
}
void print(const int1 x){
    if(x < 0){
        putchar('-');
        return uprint(-x);
    }
    return uprint(x);
}
void ps(const int1 x){
    uprint(x);
    putchar(' ');
    return ;
}
void pe(const int1 x){
    uprint(x);
    putchar('\n');
    return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n = read(),m = n - read();
    for(i = 1; i <= n; i++){
        s[i] = getc(4) ^ 48;
    }
    for(i = 1; i <= n; i++){
        c[i] = read();
        p[i] = i;
    }
    do{
        boom = 0;
        for(i = 1; i <= n; i++){
            if(!s[i] || boom >= c[p[i]]){
                boom++;
            }
        }
        if(boom <= m){
            ans++;
        }
    }while(next_permutation(p + 1,p + n + 1));
    pe(ans);
    return 0;
}
/*
I feel the pain and anger,wicked monster losing control
没时间打了cnm
*/